
#include <iostream>
#include <string>
#include <set>

class Folder;
class Message {
 friend class Folder;
 friend void swap(Message &lhs, Message &rhs) {
        using std::swap;
        // 将每个消息的指针从它（原来）所在Folder中删除
        for (auto f : lhs.folders) {
            f->remMsg(&lhs);
        }
        for (auto f : rhs.folders) {
            f->remMsg(&rhs);
        }
        // 交换contents和Folder指针set
        swap(lhs.folders, rhs.folders);     // 使用swap(set&, set&)
        swap(lhs.contents, rhs.contents);   // swap(string&, string&)
        // 将每个Message的指针添加到它的（新）Folder中
        for (auto f : lhs.folders) {
            f->addMsg(&lhs);
        }
        for (auto f : rhs.folders) {
            f->addMsg(&rhs);
        }
    }
 public:
    // folders被隐含初始化为空集合
    explicit Message(const std::string &str = "") : contents(str) {}
    // 拷贝控制成员，用来管理指向本Message的指针
    // 拷贝构造函数
    Message(const Message& message) : contents(message.contents), folders(message.folders) {
        add_to_Folders(message);  // 将本消息添加到指向message的Folder中
    } 

    // move constructor
    Message(Message &&m) : contents(std::move(m.contents)) {
        move_Folders(&m);   // 移动folders并更新Folder指针
    }

    Message& operator=(const Message& rhs) {
        // 通过先删除指针再插入来处理自赋值情况
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }

    Message& operator=(Message &&rhs) {
        if (this != &rhs) {
            remove_from_Folders();
            contents = std::move(rhs.contents);
            move_Folders(&rhs);
        }
        return *this;
    }

    ~Message() {
        remove_from_Folders();
    }

    // 从给定Folder集合中添加/删除本Message
    void save(Folder& folder) {
        addFlder(&folder);
        folder.addMsg(this);
    }

    void remove(Folder& folder) {
        remFlder(&folder);
        folder.remMsg(this);
    }


    void print_debug() {
        std::cout << contents << std::endl;
    }

 private:
    std::string contents;           // 实际消息文本
    std::set<Folder*> folders;      // 包含本Message的Folder
    // 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    void add_to_Folders(const Message& message) {
        for (auto f : message.folders) {
            f->addMsg(this);
        }
    }
    // 从folders中的每个Folder中删除本Message
    void remove_from_Folders() {
        for (auto f : this->folders) {
            f->remMsg(this);
        }
    }

    void addFlder(Folder *f) {
        folders.insert(f);
    }

    void remFlder(Folder *f) {
        folders.erase(f);
    }

    void move_Folders(Message *m) {
        folders = std::move(m->folders);   // 使用set的移动赋值运算符
        for (auto f : folders) {
            f->remMsg(m);
            f->addMsg(this);
        }
        m->folders.clear();             // 确保销毁m是无害的
    }
};


class Folder {
  friend class Message;
  friend void swap(Folder &lhs, Folder &rhs) {
      using std::swap;
      lhs.remove_from_Messages();
      rhs.remove_from_Messages();

      swap(lhs.messages, rhs.messages);

      lhs.add_to_Messages(lhs);
      rhs.add_to_Messages(rhs);
  }
 public:
    Folder() = default;
    Folder(const Folder &f) : messages(f.messages) {
        add_to_Messages(f);
    }

    Folder& operator=(const Folder &rhs) {
        remove_from_Messages();
        messages = rhs.messages;
        add_to_Messages(rhs);
        return *this;
    }

    ~Folder() {
        remove_from_Messages();
    }

    void print_debug() {
        for (auto m : messages) {
            std::cout << m->contents << " ";
        }
        std::cout << std::endl;
    }
    
 private:
    std::set<Message*> messages;
    void add_to_Messages(const Folder &rhs) {
        for(auto m : rhs.messages) {
            m->addFlder(this);
        }
    }

    void remove_from_Messages() {
        for (auto m : messages) {
            m->remFlder(this);
        }
    }

    void addMsg(Message* message) {
        messages.insert(message);
    }
    void remMsg(Message* message) {
        messages.erase(message);
    }
};


int main()
{
    return 0;
}
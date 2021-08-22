#ifndef PCB_H
#define PCB_H

#include "thread.h"
#include "synch.h"

class PCB
{
private:
    Semaphore* joinsem;         // semaphore cho quá trình join

    int exitcode;		
    char FileName[32];          // Ten cua tien trinh

    Thread* thread;             // Tien trinh cua chuong trinh
public:
    int parentID;               // ID cua tien trinh cha
    
    char boolBG;                // Kiem tra neu la tien trinh nen
    
    PCB(int = 0);               // Contructor
    ~PCB();                     // Destructor

    int Exec(char*,int);        // Tao mot thread moi
    int GetID();                // Trả về ProcessID của tiến trình gọi thực hiện
    int GetNumWait();           // Trả về số lượng tiến trình chờ


    void JoinWait();            // 1. Tiến trình cha đợi tiến trình con kết thúc
    void JoinRelease();         // 2. Báo cho tiến trình cha thực thi tiếp

    void SetExitCode(int);      // Đặt exitcode của tiến trình
    int GetExitCode();          // Trả về exitcode

    void SetFileName(char*);    // Set ten tien trinh
    char* GetFileName();        // Tra ve ten tien trinh

};

#endif // PCB_H
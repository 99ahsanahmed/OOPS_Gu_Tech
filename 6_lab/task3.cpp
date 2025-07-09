#include<iostream>
using namespace std;

class CloudStorage{
    public : 
    virtual void uploadFile(string fileName) = 0;
    virtual void downloadFile(string fileName) = 0;
    virtual void deleteFile(string fileName) = 0;
    virtual void listFiles() = 0; 
};

class AWStorage : public CloudStorage{
    private : 
    string list[100];
    int listCount = 0;
    public : 
    void uploadFile(string fileName) override {
        cout << "Uploading "<< fileName <<" to AWS.. done \n";
        list[listCount] = fileName;
        listCount++;
        cout << listCount <<"\n";
    }

    void downloadFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                cout << "Downloading "<< fileName <<" from AWS.. done \n";
                return;
            }    
        }
        cout << fileName <<" no such file found in AWS.. failed \n";
    }

    void deleteFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                for (int l = i; l < listCount ; l++)
                {
                    list[l] = list[l + 1]; 
                }
                cout << "deleting "<< fileName <<" from AWS.. done \n";
                listCount--;
                return;
            }
        }
            cout << fileName <<" no such file found in AWS.. failed \n";
    }

    void listFiles() override {
        for (int i = 0; i < listCount; i++)
        {
            cout << list[i] <<"\n";
        }
        
    }

};
class GoogleDriveStorage : public CloudStorage{
    private : 
    string list[100];
    int listCount = 0;
    public : 
    void uploadFile(string fileName) override {
        cout << "Uploading "<< fileName <<" to googleDrive.. done \n";
        list[listCount] = fileName;
        listCount++;
        cout << listCount <<"\n";
    }

    void downloadFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                cout << "Downloading "<< fileName <<" from googleDrive.. done \n";
                return;
            }    
        }
        cout << fileName <<" no such file found in googleDrive.. failed \n";
    }

    void deleteFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                for (int l = i; l < listCount ; l++)
                {
                    list[l] = list[l + 1]; 
                }
                cout << "deleting "<< fileName <<" from googleDrive.. done \n";
                listCount--;
                return;
            }
        }
            cout << fileName <<" no such file found in googleDrive.. failed \n";
    }

    void listFiles() override {
        for (int i = 0; i < listCount; i++)
        {
            cout << list[i] <<"\n";
        }
        
    }

};
class DropboxStorage : public CloudStorage{
    private : 
    string list[100];
    int listCount = 0;
    public : 
    void uploadFile(string fileName) override {
        cout << "Uploading "<< fileName <<" to dropBox.. done \n";
        list[listCount] = fileName;
        listCount++;
        cout << listCount <<"\n";
    }

    void downloadFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                cout << "Downloading "<< fileName <<" from dropBox.. done \n";
                return;
            }    
        }
        cout << fileName <<" no such file found in dropBox.. failed \n";
    }

    void deleteFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                for (int l = i; l < listCount ; l++)
                {
                    list[l] = list[l + 1]; 
                }
                cout << "deleting "<< fileName <<" from dropBox.. done \n";
                listCount--;
                return;
            }
        }
            cout << fileName <<" no such file found in dropBox.. failed \n";
    }

    void listFiles() override {
        for (int i = 0; i < listCount; i++)
        {
            cout << list[i] <<"\n";
        }
        
    }

}; 
class OneDriveStorage : public CloudStorage{
    private : 
    string list[100];
    int listCount = 0;
    public : 
    void uploadFile(string fileName) override {
        cout << "Uploading "<< fileName <<" to OneDrive.. done \n";
        list[listCount] = fileName;
        listCount++;
        cout << listCount <<"\n";
    }

    void downloadFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                cout << "Downloading "<< fileName <<" from OneDrive.. done \n";
                return;
            }    
        }
        cout << fileName <<" no such file found in OneDrive.. failed \n";
    }

    void deleteFile(string fileName) override {
        for (int i = 0; i < listCount ; i++)
        {
            if (list[i] == fileName)
            {
                for (int l = i; l < listCount ; l++)
                {
                    list[l] = list[l + 1]; 
                }
                cout << "deleting "<< fileName <<" from OneDrive.. done \n";
                listCount--;
                return;
            }
        }
            cout << fileName <<" no such file found in OneDrive.. failed \n";
    }

    void listFiles() override {
        for (int i = 0; i < listCount; i++)
        {
            cout << list[i] <<"\n";
        }
        
    }

};
int main()
{
    AWStorage aws1;
    aws1.uploadFile("abc.pdf");
    aws1.uploadFile("xyz.pdf");
    aws1.uploadFile("resume.pdf");

    cout<<"\n LISTING FILES : \n";
    aws1.listFiles();

    cout<<"\nDOWNLOADING FAKE FILE : \n";
    aws1.downloadFile("don.txt");
    
    cout<<"\nDOWNLOADING REAL FILE : \n";
    aws1.downloadFile("abc.pdf");
    
    cout<<"\nDELETING FAKE FILES : \n";
    aws1.deleteFile("don.txt");

    cout<<"\nDELETING REAL FILES : \n";
    aws1.deleteFile("resume.pdf");

    cout<<"\nUPDATED LIST : \n";
    aws1.listFiles();

    
    return 0;
}

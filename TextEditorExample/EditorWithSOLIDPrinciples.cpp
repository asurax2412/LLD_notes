#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

//abstract class for rendor element
class DocumentElement
{
    public:
    virtual string rendor() =0;
};

class TextElement: public DocumentElement
{
    private:
    string text;
    
    public:
    
    TextElement(string text){
        this->text = text;
    }
    
    string rendor() override{
        return text;
    }
};

class ImgElement : public DocumentElement
{
    private:
    string path;
    
    public:
    ImgElement(string path)
    {
        this->path =  path;
    }
    
    string rendor() override{
        return "[Image:" + path +"]";
    }
};

class NewLineElement : public DocumentElement
{
    public:
    string rendor() override{
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
    public:
    string rendor() override{
        return "\t";
    }
};

class Document
{
    private:
    vector<DocumentElement*> docElements;
    
    public:
    void addElement(DocumentElement* element){
        docElements.push_back(element);
    }
    
    string rendor(){
        string result;
        
        for(auto ele:docElements){
            result+=ele->rendor();
        }
        
        return result;
    }
};

class Presistance
{
    public:
    virtual void save (string data) =0;
};

class FileStorage : public Presistance
{
    public:
    
    void save(string data) override{
        ofstream outFile("document.txt");
        if(outFile){
            outFile<<data;
            outFile.close();
            cout<< "Documne saved to document.txt"<<endl;
        }else{
            cout<<" Error : fail to save your document" <<endl;
        }
    }
};

class DBStorage : public Presistance
{
    public:
    
    void save(string data) override{
        
    }
};

class DocumentEditor
{
    private:
    Document* document;
    Presistance* storage;
    string rendorDoc;
    
    public:
    
    DocumentEditor(Document* document,Presistance* storage){
        this->document =  document;
        this->storage =  storage;
    }
    
    
    void addText(string text){
        document->addElement(new TextElement(text));
    }
    
    void addImage(string path){
        document->addElement(new ImgElement(path));
    }
    
    void addNewLine(){
        document->addElement(new NewLineElement());
    }
    
    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }
    
    string rendorDocument(){
        if(rendorDoc.empty()){
            rendorDoc = document->rendor();
        }
        return rendorDoc;
        
    }
    
    void save(){
        storage->save(rendorDoc);
    }
};

//client element
int main() 
{
    Document* document =  new Document();
    Presistance* presistance = new FileStorage();
    
    DocumentEditor* editor =  new DocumentEditor(document,presistance);
    
    editor->addTabSpace();
    editor->addText("Hello!!! this my doc file");
    editor->addNewLine();
    editor->addImage("profile.png");
    editor->addNewLine();
    editor->addText("this is a real wprld document editor example");
    
    cout<<editor->rendorDocument()<<endl;
    editor->save();
   
   
	return 0;
}

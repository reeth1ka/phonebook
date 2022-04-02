#include<bits/stdc++.h>
using namespace std;
 
class node{
private:
     string name;
     vector<string> num;
     string email;
     node* next;
friend class linked_list;
};
void PrintVec(vector<string> &vec)  //for printing a vector
{
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << endl;
}
class linked_list{
private:
    node *head, *tail;
    int numberofcontacts;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
        numberofcontacts = 0;
    }
   ~linked_list(){  
      while (!empty()) removeFront(); 
      }
    void create_contact(string name1, vector<string> num1, string email1) // Create node and add it onto the linked list
    {
        node *temp = new node;
        temp->name = name1;
        temp->num = num1;
        temp->email = email1;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        numberofcontacts++;
    }
 
    void display_all() // Prints out current contacts
    {
        int count = 1;
        node *temp = new node;
        temp = head;
        while (temp != NULL)    // Loop through the list while the temporary node is not empty
        {
            cout << "\n\nNumber #" << count << ":"; 
            cout << "\nName: " << temp->name;
            cout << "\nContact Number: ";
            PrintVec(temp->num);
            cout << "Email: " << temp->email;
            ++count;
            temp = temp->next;
        }
    }
 
    void delete_position(int pos)   // delete a node by using the position in the list
    {
        node *current = new node;
        node *previous = new node;
        node *next = new node;
        current = head;
        for (int i = 1;i<pos;i++)   // Loop through the link list while the current node is not empty
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }
    void add_number(int pos, string num)   // adding a number to an existing contact
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1;i<pos;i++)   // loop through the list to get to the required position
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        current->num.push_back(num);   // pushing back the new number
    }
    void delete_number(int pos, int index_pos)   // delete a number of a contact using position in the list
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1;i<pos;i++)   // Loop through the link list while the current node is not empty
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        auto elem_to_remove = current->num.begin() + index_pos + 1;
       if (elem_to_remove != current->num.end()) {
        current->num.erase(elem_to_remove);
       }
    }
 
 
void search(string name_x)       // search for a contact using name
{
    node *cur = new node;
    cur = head;
    int flag=0;
 
    if(head==NULL)
        cout << "No contacts";
 
    for(int j=0; j<numberofcontacts; j++){
        if(cur->name == name_x)
        {
            cout << "\nName: " << cur->name;
            cout << "\nNumber: ";
            PrintVec(cur->num);
            cout << "Email: " << cur->email << endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout << "No contact found";
    }
}
int searchfordup(string name_y){
    node *cur = new node;
    int count=0;
    cur=head;
    if(head==NULL)
        return 0;
 
    for(int i=0; i<numberofcontacts; i++){
        if(cur->name == name_y)
        {
            return i+1;
        }
          cur = cur->next;
    }
    return 0;
}
    bool empty() const{ return head==NULL; }
    void delete_head()  // delete head node
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
   void removeFront() {			
    node* old = head;				            // save current head
    head = old->next;					        // skip over old head
    delete old;					        	    // delete the old head
}
 
};
int main()
{
    linked_list Contacts; // create a Contacts item for the List class
    int choice, position;
    string name2;
    string email2;
    vector<string> num2;
 
    while (1) {
        cout << "\nWhat would you like to do?: ";
        cout << "\n1. Show All Contacts";
        cout << "\n2. Add A Contact";
        cout << "\n3. Remove A Contact";
        cout << "\n4. Edit existing contact (add a new number)";
        cout << "\n5. Search Contacts";
        cout << "\n6. Exit The Program" << endl;
        cin >> choice;
 
        switch (choice)
        {
        case 1:
            cout << endl;
            Contacts.display_all(); // display all contacts
            cout << endl;
            break;
        case 2:
            int numofcontacts, x, positn;
            char merge;
            cout << "Enter name of the person: ";
            cin >> name2;
            positn = Contacts.searchfordup(name2);
            if(positn!=0){
               cout << "Contact with this name already exists. Would you like to merge them? (y/n) ";
               cin >> merge;
               if(merge == 'n'){
                   
               }
               if(merge == 'y'){
                   cout << "How many numbers would you like to add? ";
                   cin >> x;
               for(int i=0; i<x; i++){
               string con;
               cout <<"Enter contact: ";
               cin >> con;
               Contacts.add_number(positn, con);
               }
               break;
          } 
      }
            cout << "How many contact numbers?: ";
            cin >> numofcontacts;
            for(int i=0; i<numofcontacts; i++){
                 string contact;
                 cout <<"Enter contact: ";
                 cin >> contact;
                 num2.push_back(contact);
            }
            cout << "Enter email of the person: ";
            cin >> email2;
            Contacts.create_contact(name2, num2, email2); // create the contact in the linked list
            num2.clear();
            cout << endl;
            break;
        case 3:
            Contacts.display_all(); // display all contacts
            cout << "\n";
            int elem;
            cout << "Enter the contact you would like to remove: ";
            cin >> position;
            cout <<"Select: \n1: Delete entire contact\n2: Delete a number from the numbers list\n";
            cin >> elem;
            if(elem==1){
            if (position == 1)
                Contacts.delete_head();
            else
                Contacts.delete_position(position); } // delete contact from list
            if(elem==2){
                int index;
                cout <<"\nEnter the index of number you wish to delete: ";
                cin >> index;
                Contacts.delete_number(position, index);
            }
            break;
        case 4:
          int pos, y;
          cout << "Enter the index of the contact you would like to edit: ";
          cin >> pos;
          cout << "How many numbers would you like to add? ";
          cin >> y;
          for(int i=0; i<y; i++){
               string con;
               cout <<"Enter contact: ";
               cin >> con;
               Contacts.add_number(pos, con);
          }
          break;
        case 5:
        cout << "Enter name: ";
        cin >> name2;
        Contacts.search(name2);
          break;
        case 6:
            exit(1);
            break;
        default:
            cout << "\n" << choice << " is not an option. Please select a valid option." << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
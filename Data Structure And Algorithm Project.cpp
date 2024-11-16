#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Contact {
  string name;
  int gender;
  int age;
  string phone;
  string address;
};

struct AddressBook {
  Contact contacts[1000];
  int count = 0;
};

void showmenu() {
  cout << "********************************" << endl;
  cout << "***** Address Book Manager *****" << endl;
  cout << "********************************" << endl;
  cout << "***** 1. Add Contact        *****" << endl;
  cout << "***** 2. Display Contacts   *****" << endl;
  cout << "***** 3. Delete Contact     *****" << endl;
  cout << "***** 4. Find Contact       *****" << endl;
  cout << "***** 5. Modify Contact     *****" << endl;
  cout << "***** 6. Clear Contacts     *****" << endl;
  cout << "***** 0. Exit Address Book *****" << endl;
  cout << "********************************" << endl;
  cout << "***********Version 1.0***********" << endl;
  cout << "********************************" << endl;
}

void addContact(AddressBook* abs) {

  if (abs->count == 1000) {
    cout << "Address book is full, cannot add!" << endl;
    return;
  } else {
    // Get the contact information from the user
    string name;
    cout << "Enter name: ";
    cin >> name;
    abs->contacts[abs->count].name = name;

    int gender;
    cout << "Enter gender (1 for male, 2 for female): ";
    cin >> gender;
    abs->contacts[abs->count].gender = gender;

    int age;
    cout << "Enter age: ";
    cin >> age;
    abs->contacts[abs->count].age = age;

    string phone;
    cout << "Enter phone number: ";
    cin >> phone;
    abs->contacts[abs->count].phone = phone;

    string address;
    cout << "Enter address: ";
    cin >> address;
    abs->contacts[abs->count].address = address;

    // Increment the number of contacts
    abs->count++;
    cout << "Contact added successfully!" << endl;
    system("pause");
    system("cls");
  }
}


void displayContacts(AddressBook* abs) {
  if (abs->count == 0) {
    cout << "No contacts, please add some first!" << endl;
  } else {
    for (int i = 0; i < abs->count; i++) {
      cout << "Name: " << abs->contacts[i].name << endl;
      cout << "Gender: " << (abs->contacts[i].gender == 1 ? "Male" : "Female") << endl;
      cout << "Age: " << abs->contacts[i].age << endl;
      cout << "Phone number: " << abs->contacts[i].phone << endl;
      cout << "Address: " << abs->contacts[i].address << endl;
    }
  }
  system("pause");
  system("cls");
}
int IsExist(AddressBook* abs, string name) {
  for (int i = 0; i < abs->count; i++) {
    if (abs->contacts[i].name == name) {
      return i;
    }
  }
  return -1;
}

void DeleteContact(AddressBook* abs) {
  string name;
  cout << "Enter the name of the contact to be deleted: ";
  cin >> name;

  int index = IsExist(abs, name);
  if (index > -1) {
    for (int i = index; i < abs->count - 1; i++) {
      abs->contacts[i] = abs->contacts[i + 1];
    }
    abs->count--;
    cout << "Contact deleted successfully!" << endl;
  } else {
    cout << "Contact not found!" << endl;
  }
  system("pause");
  system("cls");
}
void FindContact(AddressBook* abs) {
  string name;
  cout << "Enter the name of the contact to be searched: ";
  cin >> name;

  int index = IsExist(abs, name);
  if (index > -1) {
    cout << "Name: " << abs->contacts[index].name << endl;
    cout << "Gender: " << (abs->contacts[index].gender == 1 ? "Male" : "Female") << endl;
    cout << "Age: " << abs->contacts[index].age << endl;
    cout << "Phone number: " << abs->contacts[index].phone << endl;
    cout << "Address: " << abs->contacts[index].address << endl;
  } else {
    cout << "Contact not found!" << endl;
  }
  system("pause");
  system("cls");
}

void ModifyContact(AddressBook* abs) {
  string name;
  cout << "Enter the name of the contact to be modified: ";
  cin >> name;
  int index = IsExist(abs, name);
  if (index > -1) {
    string newName;
    cout << "Enter the new name: ";
    cin >> newName;

    int newGender;
    cout << "Enter the new gender (1 for male, 2 for female): ";
    cin >> newGender;

    int newAge;
    cout << "Enter the new age: ";
    cin >> newAge;

    string newPhone;
    cout << "Enter the new phone number: ";
    cin >> newPhone;

    string newAddress;
    cout << "Enter the new address: ";
    cin >> newAddress;

    abs->contacts[index].name = newName;
    abs->contacts[index].gender = newGender;
    abs->contacts[index].age = newAge;
    abs->contacts[index].phone = newPhone;
    abs->contacts[index].address = newAddress;

    cout << "Contact modified successfully!" << endl;
  } else {
    cout << "Contact not found!" << endl;
  }
  system("pause");
  system("cls");
}

void ClearContacts(AddressBook* abs) {
  string choice;
  cout << "Are you sure you want to clear all contacts? (Y/N): ";
  cin >> choice;

  if (choice == "Y") {
    abs->count = 0;
    cout << "All contacts cleared successfully!" << endl;
  } else {
    cout << "Operation cancelled!" << endl;
  }
  system("pause");
  system("cls");
}
void displayMembers(string ids[], string names[], int sizes) {
    cout << setw(20) << "Name" << setw(30) << "ID" << endl;

    for (int i = 0; i < sizes; i++) {
        cout << setw(20) <<names[i] << setw(30) << ids[i]  << endl;
    }
      system("pause");
      system("cls");
}
int main() {
  AddressBook abs;
  abs.count = 0;
  string ids[] = {"ugr/30954/15", "ugr/30846/15","Ugr/31021/15","ugr/30578/15" ,"ugr/30232/15", "ugr/30232/15"};
  string names[] = {"Mohammed Ismail", "Mahfuz Redwan", "Nardos tewodros","Gadisa Yusuf","Bayisa Balcha","Bilal Ali"};
  int size = sizeof(ids)/sizeof(ids[0]);
  displayMembers(ids, names, 5);

  while (true) {
    showmenu();
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        addContact(&abs);
        break;
      case 2:
        displayContacts(&abs);
        break;
      case 3:
        DeleteContact(&abs);
        break;
      case 4:
        FindContact(&abs);
        break;
      case 5:
        ModifyContact(&abs);
        break;
      case 6:
        ClearContacts(&abs);
        break;
      case 0:
        cout << "Thank you for using the address book!" << endl;
        system("pause");
        return 0;
        break;
      default:
        cout << "Invalid input!" << endl;
        break;
    }
  }

  system("pause");
  return 0;
}

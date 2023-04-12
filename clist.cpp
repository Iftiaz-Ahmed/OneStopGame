// /*
// Program 7 - Player List
// Iftiaz Ahmed Alfi

// 10th April, 2023
// */ 

// // #include "clist.hpp"

// CList:: //-------------------------------Destructor
// ~CList() {
//     Cell* temp = head;
//     while (temp != nullptr) {
//         Cell* next = temp->next;
//         delete temp;
//         temp = next;
//     }
// }

// void CList:: //---------------------------addCell()
// addCell(Player* player) {
//     Cell* newCell = new Cell(player);
//     if (empty()) {
//         head = newCell;
//         tail = newCell;
//         current = newCell;
//     } else {
//         current->next = newCell;
//         newCell->prev = current;
//         newCell->next = head;
//         tail = newCell;
//         current = tail;
//     }
//     cellCount++;
// }

// void CList:: //-----------------------------remove()
// remove() {
//     Cell* temp = current;
//     if (head == current) {
//         current = current->next;
//         head = current;
//         tail->next = head;
//     } else {
//         temp->prev->next = current->next;
//         current = temp->next;
//     }
//     delete temp;
//     cellCount--;
// }

// CList::Cell* CList::  //------------- next()
// next() {
//     if (empty() || current->next == nullptr) return nullptr;
//     else {
//         current = current->next;
//         return current;
//     }
// }

// ostream& CList::   //---------------- print function
// print(ostream& out) {
//     if (empty()) out <<"Empty List!" <<endl;
//     else {
//         current = head;
//         do {
//             out <<*current->player;
//             current = current->next;
//         } while (current != head);
//     }
//     return out;
// }
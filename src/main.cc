#include <cstdio>
#include <string>

// void qs(char *items, int left, int right) {
//     int i, j;
//     char x, y;
//
//     i = left;
//     j = right;
//     x = items[(left + right) / 2];
//
//     do {
//         while ((items [i] < x) && (i < right)) i++;
//         while ((x < items[j]) && (j > left)) j--;
//
//         if (i <= j) {
//             y = items[i];
//             items[i] = items[j];
//             items[j] = y;
//             i++; j--;
//
//         }
//     } while (i <= j);
//     if (left < j) qs (items, left, j);
//     if (i < right) qs(items, i, right);
// }
//
// void quickSort(char *items, int len) {
//     qs(items, 0, len-1);
// }

class Animal {
   public:
      int age;
      std::string name;
      Animal(int x, std::string y): age(x), name(std::move(y)) {
         std::printf("Constructor Called");
      }

      ~Animal() {
         std::printf("Destructor Called");
      }

      void setId(const std::string& newId) {
         id = newId;
      }

      std::string getId() {
         return this->id;
      }

   private:
      std::string id;
};

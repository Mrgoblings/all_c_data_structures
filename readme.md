# The Data Structures in C

Welcome to The Data Structures in C, a library of standard data structures designed to make your life easier! 

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview
This library includes the following data structures:
- Binary Tree
- Tree
- Stack
- Queue
- Priority Queue
- Vector
- Linked List
- Doubly Linked List

Each data structure comes with a set of useful functions such as `push`, `pop`, `clear`, `size`, `contains`, `at`, and more. 

## Installation
1. Clone the repository
2. Navigate to the directory where you cloned the repository
3. Compile the library using the following command: `make`
4. Include the desired data structure header file in your project using the following command: `#include "data_structure_name.h"`

## Usage
Once you have included the desired data structure header file, you can create an instance of the data structure and use its functions. Here's an example of how to use the Linked List:

```c
#include <stdio.h>
#include "linked_list.h"
int main() {
    int input[] = {3, 10, 15, 20, 25};

    Linked_list* list = NULL;
 
    for(int i = 0; i < 5; i ++)
    	linked_list_push(&list, input + i);
   
    printf("Size is %d\n", linked_list_size(list));
    linked_list_print(list);
    
    printf("pop = %d\n", *((int*)linked_list_pop(&list)));
    linked_list_print(list);
   
    linked_list_destroy(list);
    list = NULL;
 
    return 0;
}
```

# AND
Make sure to replace "int" with the appropriate data type that you are using in your program. 

```c
void linked_list_print(Linked_list* head) {
    for(int i = 0; i < linked_list_size(head); i++)
    	printf("list[%d] = %d\n", i, *((int*)linked_list_at(head, i)));
         //! SET UP YOUR DATA TYPE HERE ^^^
                                 //!    ||
};
```

## Contributing
We welcome contributions to this library! If you find a bug or want to add a new feature, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See the LICENSE file for more information.


Happy coding!
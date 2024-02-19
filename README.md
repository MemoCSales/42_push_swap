<h1 align="center">Push_swap</h1>

<h2 align="center">
Sorting values is simple. To sort them the fastest way possible is less simple
</h2> 

## About ##

- Push_swap is an algorithm project at school 42.
- We start with two stacks called A and B.
- A is filled with some random integers (without duplicates) and B is empty.
-The goal is to sort in ascending order numbers into stack a. To do so you have the
  following operations at your disposal:

| Operation | Description |
| ---------- | ----------- |
| **sa**     | Swap A: Swap the first 2 elements at the top of stack A |
| **sb**     | Swap B: Swap the first 2 elements at the top of stack B |
| **ss**     | **sa** and **sb** at the same time |
| **pa**     | Push A: Take the first element at the top of B and put it at the top of A |
| **pb**     | Push B: Take the first element at the top of A and put it at the top of B |
| **ra**     | Rotate A: Shift up all elements of stack A by 1. The first element becomes the last one |
| **rb**     | Rotate B: Shift up all elements of stack B by 1. The first element becomes the last one |
| **rr**     | **ra** and **rb** at the same time |
| **rra**    | Reverse Rotate A: Shift down all elements of stack A by 1. The last element becomes the first one |
| **rrb**    | Reverse Rotate B: Shift down all elements of stack B by 1. The last element becomes the first one |
| **rrr**    | **rra** and **rrb** at the same time |

## Requirements ##
### Makefile ###
- NAME: This rule defines the target executable or output file that will be generated when the Makefile is executed. It is often used to specify the name of the final program or library.

- all: This rule is a common target for building the entire project. When you run make all or just make without specifying a target, it usually builds the entire project. It often depends on other specific targets (e.g., compiling source files, linking objects, etc.).

- clean: This rule is used to clean up the project by removing any generated files that can be recompiled. It typically deletes object files (.o) and any other temporary files, leaving only the source code.

- fclean: This rule goes a step further than clean and removes all generated files, including the final executable. It essentially leaves the project in a state as if it was just checked out from version control and nothing has been built yet.

- re: This rule is a shorthand for doing a clean build. It first performs fclean to remove all generated files and then runs the all rule to rebuild the project from scratch. It's useful when you want to ensure a complete rebuild of your project.

### Allowed Functions ###
 - read
 - write
 - malloc
 - free
 - exit
 - ft_printf or equivalent

## Results ##
- According with [gemartin99 Tester](https://github.com/gemartin99/Push-Swap-Tester) (thank you for this amazing tester!)
### Multiple size <= 100 ###
MOVES:
- Min: 530      :white_check_mark:
- Average: 595  :white_check_mark:
- Max: 671      :white_check_mark:
### Multiple size <= 500 ###
MOVES:
- Min: 4374     :white_check_mark:
- Average: 4785 :white_check_mark:
- Max: 5144     :white_check_mark:

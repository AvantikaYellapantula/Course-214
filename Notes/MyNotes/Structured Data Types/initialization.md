***Initialization***

C allows the following to be given initial values in their definitions:

- ordinary variables
- structures
- unions
- arrays

There are two sorts of initialization:

- compile time
- run time

Which one you get depends on the storage duration of the thing being initialized:

- static duration: Objects with static duration are declared either outside functions or inside them with the keyword ```extern``` or ```static``` as part of the declaration. These can *only* be initialized at compile time
- automatic duration - Any other object has automatic duration and can only be initialized at run time.
- Note: The two categories are mutually exclusive

**Key changes**

1. The Cell class had a set of set and get methods. Instead, we will replace each pair with a pair of overloaded reference methods.
2. The previous list could only store values of the type double. Now we will define the list to be **template**, which allows it to store values of any type.
3. We will replace some of the methods with overloaded operators. Cell and Iterator were free-standing classes. Now we will let them be inner classes, defined inside LinkedList.

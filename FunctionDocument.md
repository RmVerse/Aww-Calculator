# Function Document

## List

### About using of define

+ and
+ or
+ in
+ is
+ not
+ of
+ as
+ to
+ asWithout
+ toWithout
+ without
+ with


### `and` `or` `in` `is` `not`  
It is used for condition.

```C
#define and &&  
#define or ||  
#define in ==  
#define is ==  
#define not !  
```

```C
if(condition1 and condition2 or not condition3) {
    // ...
}

if(num is 1) {
    // ...
}
```

### `step`  
It only used to `for()`.
```C
#define step +=
```

```C
for(int num = 0; num < 10; num step 1) {
    // ...
}
```

### `of`  
It is used for value.
```C
#define of =
```

```C
int num of 0;
```


#define as >=
#define to <=

#define asWithout >
#define toWithout <

#define without(x) -x
#define with(y) +y

## About using of 

+ for() when() ...
+ for() if() ...
+ 
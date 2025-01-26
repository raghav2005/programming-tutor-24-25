-- this is a single-line comment

{-
this is a
multi-line comment
-}


-- primitive data types
bool_example :: Bool -- :: means defining the type
bool_example = True -- True or False

char_example :: Char
char_example = 'H' -- represents a single character - must be single quotes

int_example :: Int
int_example = 42 -- integer

float_example :: Float
float_example = 3.14 -- single-precision floating-point number

double_example :: Double
double_example = 3.14159 -- double-precision floating-point number

string_example :: String
string_example = "Hello, Haskell!" -- list of Chars - must be double quotes


-- in ghci, you can do :t <variable / function> to get the type definition of the variable/function


-- lists - must be homogeneous (same data type)
nums :: [Int]
nums = [1,2,3,4,5] -- haskell convention is usually no space
-- note: you can specify ranges with .. e.g. [1..5]
-- similarly, you can do a sequence e.g. [3,6..27]
-- infinite lists are possible e.g. [1..]

-- tuples - fixed-size, but can be any data type
pair :: (String, Int, Bool)
pair = ("hello", 3, False)

-- list of tuples
pairs :: [(String, Int, Bool)]
pairs = [("hello", 3, False), ("bye", 2, True)] -- each element of the list (tuple) must still have 3 elements in the specified order to match the type

-- tuples of lists
list_pairs :: ([Int], [Char])
list_pairs = ([1..20], ['a'..'c'])


-- haskell is lazy by default, so for something like take 2 [1..10000000] haskell will only need to generate [1..2] as it won't evaluate an expressions until it's needed

-- haskell is also statically typed - data types defined during compile time and can't be changed during runtime, which enables the compiler to have static type checking so there will be fewer errors, but less freedom


-- all functions are defined as follows:
-- function-name :: type -- this line is optional in the language, but you MUST specify the type for this module
-- function-name arguments 

my_func :: Bool -> Bool -- takes in a boolean and returns a boolean
my_func x = x -- just return the value

bool_and :: Bool -> Bool -- takes in a boolean and returns a boolean
bool_and x = x && True -- just return the value


addition :: Int -> (Int -> Int) -- same as Int -> Int -> Int (HASKELL FUNCTIONS ARE RIGHT ASSOCIATIVE)
addition x y = x + y

-- addition2 takes int x and returns a function partial_add
addition2 :: Int -> Int -> Int
addition2 x = partial_add
    where partial_add y = x + y -- where introduces a local definition

-- functions in haskell are usually prefix by default e.g. addition 3 5 (addition isn't actually a haskell function, I'm just using the one I defined above as an example)
-- to use a prefix function as infix, you can surround the function in `` so 3 `addition` 5 would work
-- to use an infix function as prefix, you would surround it in () so 3 + 5 would become (+) 3 5


-- higher-order functions - functions where functions can be passed as arguments or returned as values
apply_twice :: (a -> a) -> a -> a -- a is a generic type variable
apply_twice f x = (f (f x)) -- f(f(x))
-- succ is the same as + 1, so apply_twice succ 3 == 5


-- can also define a very simple function with just brackets e.g. a function that adds 3 to a number can be defined as (+3), so we could do apply_twice (+3) 5


greater_than :: Int -> Int -> Bool
greater_than x y = if x > y then True else False -- this is an inline if statement


less_than :: Int -> Int -> Bool
-- this is called a block if statement
less_than x y = if x < y
                    then True
                else if x > y
                    then False
                else False


comparison :: Ord a => a -> a -> Int -- don't worry about the Ord a => part too much - we'll cover this later but it's basically saying bound a so that it has be comparable / ordered as a type
comparison x y
    | x == y = 0
    | x > y = 1
    | otherwise = -1


-- pattern matching is a very useful feature
-- whatever is further up / first in the code happens first, unlike python, for example
factorial :: Int -> Int
factorial 0 = 1
factorial 1 = 1 -- don't explicitly need this, just 0 and n cases would suffice
factorial 2 = 2
factorial n = n * factorial (n - 1)

func1 :: Int -> Int -> Int
func1 1 1 = 0
func1 1 _ = 1
func1 _ 1 = 1
func1 x y = x + y + 1


-- list comprehension is also very useful in haskell
squares :: [Int] -> [Int]
squares xs = [x * x | x <- xs]
-- we usually refer to lists by xs, ys, etc.
-- the code above is basically saying for each x in xs (the input list), let the value in the new list be (append to the new list) x^2

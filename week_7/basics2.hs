-- how would you increment all values in a list by 1?
-- version 1
addOne :: Int -> Int
addOne x = x + 1

addList :: [Int] -> [Int]
addList xs = map addOne xs

-- version 2
addOne' :: Int -> Int
addOne' = (+1)

addList' :: [Int] -> [Int]
addList' xs = map addOne' xs
{-
line above could be replaced with:
addList' = map addOne'
-}

-- version 3 - using a lambda function
addList'' :: [Int] -> [Int]
addList'' xs = map (\x -> x + 1) xs


multiply :: Int -> Int -> Int
multiply x y = x * y

-- partially applied function
double = multiply 2

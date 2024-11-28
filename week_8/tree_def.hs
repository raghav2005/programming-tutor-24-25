import qualified Data.Tree (Tree(..), drawTree) -- ignore this

-- define a binary tree
data Tree a = Empty
            | Node (Tree a) a (Tree a)
            deriving (Show, Eq)


{-
        10
       /  \
      5    15
     / \     \
    2   8     20
-}
example_tree :: Tree Int
example_tree = Node
                 (Node
                      (Node Empty 2 Empty)
                      5
                      (Node Empty 8 Empty)
                 )
                 10
                 (Node
                      Empty
                      15
                      (Node Empty 20 Empty)
                 )


-- in-order traversal
inorder :: Tree a -> [a]
inorder tree = go tree []
  where
    go Empty acc = acc
    go (Node left val right) acc = go left (val : go right acc)

-- pre-order traversal
preorder :: Tree a -> [a]
preorder tree = go tree []
  where
    go Empty acc = acc
    go (Node left val right) acc = val : go left (go right acc)

-- post-order traversal
postorder :: Tree a -> [a]
postorder tree = go tree []
  where
    go Empty acc = acc
    go (Node left val right) acc = go left (go right (val : acc))


insert :: Ord a => a -> Tree a -> Tree a
insert x Empty = Node Empty x Empty
insert x (Node l v r)
    | x < v     = Node (insert x l) v r
    | x > v     = Node l v (insert x r)
    | otherwise = Node l v r -- ignore duplicates


search :: Ord a => a -> Tree a -> Bool
search _ Empty = False
search x (Node l v r)
    | x == v    = True
    | x < v     = search x l
    | otherwise = search x r


height :: Tree a -> Int
height Empty = 0
height (Node l _ r) = 1 + max (height l) (height r)


count_nodes :: Tree a -> Int
count_nodes Empty = 0
count_nodes (Node l _ r) = 1 + count_nodes l + count_nodes r

is_balanced :: Tree a -> Bool
is_balanced Empty = True
is_balanced (Node l _ r) =
    abs (height l - height r) <= 1 && is_balanced l && is_balanced r


list_to_tree :: [a] -> Tree a
list_to_tree [] = Empty
list_to_tree xs = Node (list_to_tree l) v (list_to_tree r)
    where
        (l, v:r) = splitAt (length xs `div` 2) xs


mirror :: Tree a -> Tree a
mirror Empty = Empty
mirror (Node l v r) = Node (mirror r) v (mirror l)


map_tree :: (a -> b) -> Tree a -> Tree b
map_tree _ Empty = Empty
map_tree f (Node l v r) = Node (map_tree f l) (f v) (map_tree f r)


------------------- IGNORE THE CODE BELOW -------------------------------------

to_data_tree :: Show a => Tree a -> Data.Tree.Tree String
to_data_tree Empty = Data.Tree.Node "Empty" []
to_data_tree (Node left val right) =
  Data.Tree.Node (show val) [to_data_tree left, to_data_tree right]

show_tree :: Show a => Tree a -> IO ()
show_tree x = putStrLn $ Data.Tree.drawTree $ to_data_tree x

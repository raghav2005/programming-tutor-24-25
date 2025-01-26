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


-- python
-- arr = []

-- def inorder(node):
--     global arr

--     inorder(node.left)
--     arr.append(node.value)
--     inorder(node.right)


betterPreOrder :: Tree a -> [a]
betterPreOrder Empty = []
betterPreOrder (Node left val right) = [val] ++ betterPreOrder left ++ betterPreOrder right

betterInOrder :: Tree a -> [a]
betterInOrder Empty = []
betterInOrder (Node left val right) = betterInOrder left ++ [val] ++ betterInOrder right

betterPostOrder :: Tree a -> [a]
betterPostOrder Empty = []
betterPostOrder (Node left val right) = betterPostOrder left ++ betterPostOrder right ++ [val]

-- pre-order traversal
preorder :: Tree a -> [a]
preorder tree = go tree []
  where
    go Empty acc = acc
    go (Node left val right) acc = val : go left (go right acc)

-- preorder (Node (Node Empty 5 Empty) 10 (Node Empty 15 (Node Empty 20 Empty))) => x

-- go (Node (Node Empty 5 Empty) 10 (Node Empty 15 (Node Empty 20 Empty))) []

-- 10 : go (Node Empty 5 Empty) (go (Node Empty 15 (Node Empty 20 Empty)) [])

-- 10 : (5 : go Empty (go Empty [])) (go (Node Empty 15 (Node Empty 20 Empty)) [])

-- 10 : (5 : []) (go (Node Empty 15 (Node Empty 20 Empty)) [])

-- 10 : (5 : []) (15 : go Empty (go (Node Empty 20 Empty) []))

-- 10 : (5 : []) (15 : go Empty (20 : go Empty (go Emtpy [])))

-- 10 : (5 : []) (15 : go Empty [20])

-- 10 : (5 : []) (15 : [20])

-- 10 : (5 : []) [15, 20])

-- [10, 5, 15, 20])

-- post-order traversal
postorder :: Tree a -> [a]
postorder tree = go tree []
  where
    go Empty acc = acc
    go (Node left val right) acc = go left (go right (val : acc))


tree_foldr :: (a -> b -> b) -> b -> Tree a -> b
tree_foldr _ acc Empty = acc
tree_foldr f acc (Node l v r) = tree_foldr f (f v (tree_foldr f acc r)) l
-- remember for foldr we start from the right, so we essentially want to fold the right first, then the value, then left
-- evaluating the brackets from the inside-out

tree_foldl :: (b -> a -> b) -> b -> Tree a -> b
tree_foldl _ acc Empty = acc
tree_foldl f acc (Node l v r) = tree_foldl f (f (tree_foldl f acc l) v) r
-- similarly, we want to stat from the left, then the value, then the right


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

-- This is AI-generated cuz I couldn't really be asked to write everything myself
import Control.Monad (when)

-- Introduction to Monads
-- ----------------------
-- Monads are a way to handle computations in a specific context (e.g., computations that might fail, involve state, or produce side effects).
-- They can be thought of as "programmable semicolons" that allow chaining of operations while handling context automatically.
-- A Monad is defined by three key components:
-- 1. `return` (or `pure` in newer libraries): Puts a value into the monadic context.
-- 2. `>>=` (bind): Chains computations while maintaining the monadic context.
-- 3. Laws (associativity, left identity, right identity) that ensure consistent behavior.

-- Monad Typeclass
-- ----------------
-- class Monad m where
--   return :: a -> m a           -- Embeds a value into the monadic context.
--   (>>=)  :: m a -> (a -> m b) -> m b -- Chains two computations together.

-- Let's look at some examples of Monads:

-- Example 1: Maybe Monad (handling computations that might fail)
maybeExample :: Maybe Int
maybeExample = do
    x <- Just 5              -- Extract value 5 from `Just 5`
    y <- Just 10             -- Extract value 10 from `Just 10`
    return (x + y)           -- Combine the values and return them in the monadic context

-- Example 2: List Monad (non-deterministic computations)
listExample :: [Int]
listExample = do
    x <- [1, 2, 3]           -- Take each value from the list
    y <- [4, 5]              -- Combine each value with another list
    return (x + y)           -- Return all possible combinations

-- Example 3: IO Monad (handling side effects)
ioExample :: IO ()
ioExample = do
    putStrLn "Enter your name:"   -- Print to the console
    name <- getLine               -- Read input from the user
    when (not (null name)) $ do   -- Execute only if the name is not empty
        putStrLn $ "Hello, " ++ name ++ "!"

-- Monad Laws
-- ----------
-- Monads must satisfy three laws to ensure consistency:
-- 1. Left identity: `return a >>= f` is equivalent to `f a`
-- 2. Right identity: `m >>= return` is equivalent to `m`
-- 3. Associativity: `(m >>= f) >>= g` is equivalent to `m >>= (\x -> f x >>= g)`

-- Let's verify the Monad laws with Maybe:

-- Left Identity
leftIdentityCheck :: Bool
leftIdentityCheck = (return 10 >>= (\x -> Just (x + 5))) == (\x -> Just (x + 5)) 10

-- Right Identity
rightIdentityCheck :: Bool
rightIdentityCheck = (Just 10 >>= return) == Just 10

-- Associativity
associativityCheck :: Bool
associativityCheck =
    ((Just 10 >>= (\x -> Just (x + 5))) >>= (\y -> Just (y * 2))) ==
    (Just 10 >>= (\x -> (\y -> Just (y * 2)) =<< Just (x + 5)))

-- Run examples
main :: IO ()
main = do
    -- Run Maybe Monad example
    print maybeExample

    -- Run List Monad example
    print listExample

    -- Run IO Monad example
    ioExample

    -- Verify Monad laws
    print ("Left Identity: " ++ show leftIdentityCheck)
    print ("Right Identity: " ++ show rightIdentityCheck)
    print ("Associativity: " ++ show associativityCheck)

# sudoku-solver
a sudoku solver implemented in c++
this project solves any valid **9x9 SUDOKU** using **BACKTRACKING ALGORITHM** IN C++.

## algorithm

```
find an empty cell
      │
      ▼
 try digits 1 → 9
      │
      ▼
 is it valid?
   │       │
   no     yes
   │       │
   ▼       ▼
next    place digit
digit       │
            ▼
     solve recursively
             │
          SUCESS?
          │    │
         YES   NO
          │    │
          ▼    ▼
    finish  backtrack ↩
```

*(•‿•) Keep trying until the puzzle is solved.*

## time complexity

worst case:

```
O(9^81)
```

## 👩‍💻 Author
**Aditi Ranjan**

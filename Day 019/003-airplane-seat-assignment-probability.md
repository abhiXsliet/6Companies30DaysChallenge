# Nth Person Gets Nth Seat ? 🤔

This repository addresses the classic problem of finding the probability that the nth person obtains their assigned seat in an airplane with n seats.

## Problem Statement

Consider an airplane with n seats, where each passenger is assigned a specific seat. The first passenger, however, loses their ticket and randomly selects a seat. Subsequent passengers follow two rules:

- They take their designated seat if it's available.
- If their seat is occupied, they randomly choose another available seat.

The goal is to calculate the probability that the nth person ends up in their assigned seat.

## Solution

The C++ solution is succinct:

```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return (n == 1) ? 1.0 : 0.5;
    }
};
```

## Explanation

- If there is only one passenger (n=1), he will definitely get his own seat. So, the probability is 1.0.

- If there are more than one passengers (n>1), the first passenger will either take his own seat or the nth passenger's seat. If the first passenger takes his own seat, then all the other passengers will take their own seats (since their seats are available), and the nth passenger will get his own seat. This scenario happens with a probability of 0.5. If the first passenger takes the nth passenger's seat, then the nth passenger will not get his own seat. This scenario also happens with a probability of 0.5.

- If the first passenger takes any other seat (not his own and not the nth passenger's), it will start a chain of displacements such that the passenger whose seat was taken will take another seat. This chain will continue until either the first seat or the nth seat is taken. If the first seat is taken, the cycle of displacements will stop and all the remaining passengers will take their own seats, so the nth passenger will get his own seat. If the nth seat is taken, the nth passenger will not get his own seat. Both these scenarios are equally likely, so they happen with a probability of 0.5 each.

- Therefore, the total probability that the nth passenger gets his own seat is 0.5.


## Proof By Contradiction

Assume the probability that the nth person gets their own seat is not 0.5.


1. If there is only one passenger (n=1), he will definitely get his own seat. So the probability is 1, not 0.5. This does not contradict our assumption.

2. If there are two passengers (n=2), the first passenger will either take his own seat or the second passenger's seat. So the second passenger has a 0.5 probability of getting his own seat. This contradicts our assumption that the probability is not 0.5.

3. For n > 2, consider the first passenger. He will either take his own seat or the nth passenger's seat or one of the other seats. If he takes his own seat, then all the other passengers will get their own seats, so the nth passenger will get his own seat. If he takes the nth passenger's seat, then the nth passenger will not get his own seat. If he takes one of the other seats, say the ith seat, then the problem reduces to the same problem with i passengers, which we have already solved.

So in all cases, the probability that the nth passenger gets his own seat is 0.5. This contradicts our assumption that the probability is not 0.5. Therefore, our assumption is wrong, and the probability that the nth passenger gets his own seat is indeed 0.5. This completes the proof by contradiction.

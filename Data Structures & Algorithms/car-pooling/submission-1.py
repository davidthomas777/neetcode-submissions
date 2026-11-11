import numpy as np

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips = np.array(trips)
        n = np.max(trips[:,2])
        steps = np.arange(n)
        mask = (trips[:, 1, None] <= steps) & (trips[:, 2, None] > steps)

        total = (mask * trips[:, 0, None]).sum(axis=0)

        return not np.any(total > capacity)
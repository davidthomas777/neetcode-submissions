import numpy as np

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips = np.array(trips)
        n = np.max(trips[:,2])
        print(n)
        for i in range(n+1):
            total = 0
            for trip in trips:
                if i >= trip[1] and i < trip[2]:
                    total += trip[0]
            if total > capacity:
                return False
        return True
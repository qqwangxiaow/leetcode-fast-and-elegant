#这题真无语
class Solution(object):
    def isNumber(self, s):
        try:
            float(s)
            return True
        except ValueError:
            return False
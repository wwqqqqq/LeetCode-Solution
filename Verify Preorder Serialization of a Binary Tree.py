# No.331

class Solution:
    def isValid(self, nodes):
        if len(nodes) == 0:
            return False
        if nodes[0] == 0:
            del nodes[0]
            return True
        
        del nodes[0] # delete the root of root
        
        # Validate and delete left tree
        if len(nodes) == 0:
            return False
        if Solution.isValid(self, nodes) == False:
                return False
        
        # Validate and delete right tree
        if len(nodes) == 0:
            return False
        if Solution.isValid(self, nodes) == False:
                return False
        return True
        
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        preorder = preorder.split(',')
        nodes = []
        for i in preorder:
            if i == '#':
                nodes.append(0)
            else:
                nodes.append(1)
        if Solution.isValid(self, nodes) == False:
            return False
        if len(nodes) > 0:
            return False
        return True
    
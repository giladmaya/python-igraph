import unittest
from igraph import *

class DirectedUndirectedTests(unittest.TestCase):
    def testToUndirected(self):
        graph = Graph([(0,1), (0,2), (1,0)], directed=True)

        graph2 = graph.copy()
        graph2.to_undirected(collapse=False)
        self.failUnless(graph2.vcount() == graph.vcount())
        self.failUnless(graph2.is_directed() == False)
        self.failUnless(sorted(graph2.get_edgelist()) == [(0,1), (0,1), (0,2)])

        graph2 = graph.copy()
        graph2.to_undirected()
        self.failUnless(graph2.vcount() == graph.vcount())
        self.failUnless(graph2.is_directed() == False)
        self.failUnless(sorted(graph2.get_edgelist()) == [(0,1), (0,2)])

        graph2 = graph.copy()
        graph2.es["weight"] = [1,2,3]
        graph2.to_undirected(collapse=True, combine_edges="sum")
        self.failUnless(graph2.vcount() == graph.vcount())
        self.failUnless(graph2.is_directed() == False)
        self.failUnless(sorted(graph2.get_edgelist()) == [(0,1), (0,2)])
        self.failUnless(graph2.es["weight"] == [4,2])

    def testToDirected(self):
        graph = Graph([(0,1), (0,2), (2,3), (2,4)], directed=False)
        graph.to_directed()
        self.failUnless(graph.is_directed())
        self.failUnless(graph.vcount() == 5)
        self.failUnless(sorted(graph.get_edgelist()) == \
                [(0,1), (0,2), (1,0), (2,0), (2,3), (2,4), (3,2), (4,2)]
        )


def suite():
    direction_suite = unittest.makeSuite(DirectedUndirectedTests)
    return unittest.TestSuite([direction_suite])

def test():
    runner = unittest.TextTestRunner()
    runner.run(suite())
    
if __name__ == "__main__":
    test()

Leading Question:
Our group wishes to graphically represent the different taxonomic groups on Earth and the species that they contain. Using this graphical representation, we can determine the relatedness of two species by examining the distance between their nodes in the graph. We can also determine the smallest taxonomic grouping that two species share using this graph. This graph will be more of a general search/education tool as opposed to solving a specific problem.

Dataset Acquisition and Processing:
https://www.catalogueoflife.org/data/download
This dataset represents a list of all species on earth. We used the TextTree download, as it comes pre-sorted into a tree structure, allowing us to more easily parse the text file into a tree. We store the raw data in a text file as that is what it comes in, but we can save the tree structure into different text files that store the children of a given node to split the data into smaller sets in order to improve runtime.
Each Node represents a level of the taxonomic tree. The largest, and least specific, grouping we are working with is Kingdom: Animals, Plants, Fungi, etc. The next is Phylum. For example the phylum Chordata contains all animals with bilateral symmetry as opposed to radial. The next grouping is Class, an example being Mammalia that contains all mammals. The next least specific grouping is Order, humans are in the Primate order. The next grouping is Family, humans belong to Hominidae. Then Genus, of which humans belong to Homo, then finally Species of which humans are Sapiens. All leaf nodes will be of the rank species, with their parents being nodes that are less and less specific. Each non-leaf node has child nodes that are more specific, and thus the edges denote this relationship. All species on Earth are related to each other, the only question is to what degree. Species in the same Family will be more related than species who are only in the same Class.

Graph Algorithms: 
One algorithm that works for this dataset and what we are trying to do with it is Dijkstra's shortest path algorithm. As we are looking for the shortest path between two species, this works. For this algorithm, we will assign a weight of one to all edges, since no edge is more important than any other. We will then take in two species as the input and will output the number of edges between them, and their lowest common parent. Another algorithm we would implement is a standard BFS, as if a user only has a species name to search for and no other information, then we effectively have to do a linear search on our data. However, in our find function we will provide the option for the search to include other taxonomic data to allow the user to cut down on runtime. The other complex algorithm we will use will be determining betweenness centrality using Brandes’ algorithm since it runs in O(|V||E|) time for an unweighted graph. Determining the centrality of certain areas of the tree of life shows areas where life diversified at some point in Earth’s past.

Timeline:
Order of tasks:
Data Acquisition has already been completed
Tree Construction will occur first. (first half of time allotted)
Tree Structure will contain nodes with values for:
Level of Tree (kingdom, phylum, order, etc)
Name (Animalia, Homo, Sapiens, etc)
writeToFile
readFromFile
Vector containing a list of all children of the node
Implementation of Tree Function / Complex Algorithms (second half of time allotted):
findNode (given level and name, return node)
findParent (returns the parent Node of a Node)
distanceBetween (returns number of edges between 2 nodes)
lowestCommonGrouping (returns most specific node containing both inputs)
findMostConnected (finds the most connected descendant of the input Node)


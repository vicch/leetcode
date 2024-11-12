"""
File system is naturally a trie structure, but this problem doesn't have traversal use case. The content of each level of directory can be a
simple k-v pair in a hashmap:

{
    "/": {"foo"},
    "/foo": {"bar"},
    "/foo/bar": {"file"}
}

And the file contents can be another hashmap keyed by file path.

The tricky part is to handle the root dir `/`, which is irregular comparing with deeper levels `/foo/bar` etc.

Time complexity:
- ls: O(1) for file, O(NlogN) for dir, N = number of entries in dir
- mkdir: O(N), N = depth
- addContent: O(N), N = depth, due to mkdir()
- readContent: O(1)

Space complexity:
- O(N * M) for file contents, N = number of files, M = average length
- O(N * M) for paths: N = number of paths, M = average depth
"""
class FileSystem(object):

    def __init__(self):
        self.paths = defaultdict(set)
        self.files = defaultdict(str)
        

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        if path in self.files:
            file = path.split("/")[-1]
            return [file]

        return sorted(list(self.paths[path]))
        

    def mkdir(self, path):
        """
        :type path: str
        :rtype: None
        """
        if path in self.paths:
            return

        dirs = path.split("/")
        for i in range(len(dirs) - 1):
            curr = "/".join(dirs[:i+1])
            if curr == "":
                curr = "/"
            if dirs[i+1] != "":
                self.paths[curr].add(dirs[i+1])
        

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: None
        """
        parts = filePath.split("/")

        dirPath = "/".join(parts[:-1])
        if dirPath == "":
            dirPath = "/"
        self.mkdir(dirPath)
    
        file = parts[-1]
        self.paths[dirPath].add(file)

        self.files[filePath] += content
        

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        return self.files[filePath]

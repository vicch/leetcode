// Problem:
// Given n processes, each process has a unique PID (process id) and its PPID
// (parent process id). Each process only has one parent process, but may have
// one or more children processes. Only one process has PPID that is 0, which
// means this process has no parent process. All the PIDs will be distinct
// positive integers. Given two lists of integers to represent processes, where
// the first list contains PID for each process and the second list contains
// the corresponding PPID. Given a PID representing a process you want to kill,
// return a list of PIDs of processes that will be killed in the end. Assume
// that when a process is killed, all its children processes will be killed.
// The given kill id is guaranteed to be one of the given PIDs.
// 
// Example:
// Input: [1, 3, 10, 5]
//        [3, 0, 5, 3]
//        5
// Output: [5,10]
// 
// Solution:
// Use a map to store PID and list of children PIDs. Iterate the two lists to
// populate the map. Then start from the PID to kill, populate PIDs and its
// children PIDs into another list. Continue till the end of the list (when no
// more PIDs in the list has children PIDs).

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int i;
        map<int, vector<int>> pl;
        vector<int> kl;
        
        // Populate map
        for (i = 0; i < pid.size(); i++)
            pl[ppid[i]].push_back(pid[i]);
        
        // Push first PID (PID to kill)
        kl.push_back(kill);
        
        // Populate children PIDs
        for (i = 0; i < kl.size(); i++)
            for (int id: pl[kl[i]])
                kl.push_back(id);
        
        return kl;
    }
};
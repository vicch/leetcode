// Problem:
// A log entry contains a unique ID and timestamp. Timestamp is a string that
// has the following format: Year:Month:Day:Hour:Minute:Second, for example,
// 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.
// 
// Design a log storage system to implement the following functions:
// 
// void Put(int id, string timestamp)
// Given ID and timestamp, store the log in storage system.
// 
// int[] Retrieve(String start, String end, String granularity)
// Return log IDs within the range from start to end. Start and end all have
// the same format as timestamp. Granularity means the time level for
// consideration. For example, start = "2017:01:01:23:59:59", end =
// "2017:01:02:23:59:59", granularity = "Day", it means to find the logs within
// the range from Jan. 1st 2017 to Jan. 2nd 2017.
// 
// Example:
// Input: put(1, "2017:01:01:23:59:59");
//        put(2, "2017:01:01:22:59:59");
//        put(3, "2016:01:01:00:00:00");
//        retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");
//        retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
// Output: [1,2,3]
//         [1,2]
//         
// Solution:
// Consider each timestamp as an integer value, use this value as key, and log
// ID as value to save each log entry into a map. And by finding the bounds of
// the start and end timestamp, a range of log entries can be retrieved. The
// granularity can be considered as a mask, used to ignore the last several
// digits of the start/end timestamp, and the end timestamp should be
// incremented to represent the upper bound. For example,
// retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"), start would be
// 20160101010000 (last 4 digits ignored), and end would be 20170101240000 (
// last 4 digits ignored, and hour incremented by 1).

class LogSystem {
public:
    LogSystem() {}
    
    void put(int id, string timestamp) {
        logs[convert_time(timestamp, 0, 0)] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> ids;

        int mask = get_mask(gra);

        // Find lower and upper bounds
        auto f = logs.lower_bound(convert_time(s, mask, 0));
        // Do not increment when granularity is "Second"
        auto t = logs.upper_bound(convert_time(e, mask, (mask != 0) ? 1 : 0));

        for (auto i = f; i != t; i++)
            ids.push_back(i->second);

        return ids;
    }

private:
    map<long, int> logs;

    // Convert timestamp in integer value
    long convert_time(string timestamp, int mask, int incr) {
        long id = 0;

        // i is char index
        // j is count of digits read
        // Assume total number of digits is 14
        for (int i = 0, j = 0; j < 14 - mask; i++) {
            // Ignore delimeters
            if (timestamp[i] == ':')
                continue;
            // Read one digit
            j++;
            id *= 10;
            id += (timestamp[i] - '0');
        }

        // Increment for upper bound
        id += incr;

        // Pad masked digits by 0
        for (; mask > 0; mask--)
            id *= 10;

        return id;
    }

    int get_mask(string gra) {
        switch (gra[0]) {
            case 'Y':
                return 10;
            case 'M':
                return gra[1] == 'o' ? 8 : 2;
            case 'D':
                return 6;
            case 'H':
                return 4;
            default:
                return 0;
        }
    }
};
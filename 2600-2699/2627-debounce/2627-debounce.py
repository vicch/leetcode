class Solution(object):
    def debounce(self, t, calls):
        executions = []
        
        # Iterate the calls, if any call can be executed with debounce before the next call, execute it.
        for i in range(len(calls) - 1):
            if calls[i]["t"] + t < calls[i+1]["t"]:
                executions.append({"t": calls[i]["t"] + t, "inputs": calls[i]["inputs"]})

        # The last one should always be executed.
        executions.append({"t": calls[-1]["t"] + t, "inputs": calls[-1]["inputs"]})

        return executions

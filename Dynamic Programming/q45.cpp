// ALGORITHM:
// sort the given jobs on the basis of finish time
// use bottom up/ tabulation DP, table of size n (n: no of jobs) [1-D matrix]
// iterate through each job, i have two possibilities: take the job ignore the job
// ignore the job : dp[i] = dp[i-1]
// take the job: 
// do a binary search in finish time of jobs[0...i-1] with key as start time of job[i]
// let the position be pos
// dp[i] = max (dp[i], dp[pos]+job_val[i])

// Refer https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/ for code
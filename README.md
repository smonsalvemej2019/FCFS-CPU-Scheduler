# FCFS-CPU-Scheduler
<h1>Updates by date</h1> 

<h2>03/4/21</h2>
<p>I decided to turn the code I had for single linked list using object-oriented programming</p> 
<p>into code for double linked list data structures. My plan is to implement 2 (maybe 3 queues)</p>
<ul>
	<li>A waiting queue.</li>
	<li>An I/O queue.</li>
	<li>A CPU queue.</li>
</ul>
<p>I might use loops to update the data inside each node</p>
<h1>ABOUT DATA</h1>
<p>The data given to me is in the form of an integer array for each process in the form CPU burst, I/O time, CPU burst, I/O time etc.</p> 
<p>The simulation needs to calculate waiting time(WT), response time(RT), and turnaround time(TT).</p>
<p>So far the data I need in the node structure is the following.</p>
<ul>
	<li>Array data – Will use pointers to pass the arrays</li>
	<li>Array counter – An integer will do. Array counters will be different for each process</li>
	<li>Global counter – This will represent a single time quanta. It is related to RT WT and TT.</li>
	<li>The global counter might be outside the class.</li>
</ul>

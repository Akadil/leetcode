<div class="my-div"><h1 id="introduction-to-graphs">Introduction to Graphs</h1>
<hr>
<p>We have actually encountered graphs multiple times so far in the course. A graph is a data structure made up of nodes (which we have seen in form of TreeNodes and ListNodes) and possibly pointers connecting them together.</p>
<p>Let's cover some graph terminology first.</p>
<hr>
<h2 id="graph-terminology">Graph Terminology</h2>
<p>In graphs, nodes are referred to as <strong>vertices</strong> and the pointers connecting these nodes are referred to as <strong>edges</strong>. There are no restrictions in graphs when it comes to where the nodes are placed, and how the edges connect those nodes together.</p>
<p>It is also possible that the nodes are not connected by any edges and this would still be considered a graph - a null graph.</p>
<p>The number of edges, <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>E</mi></mrow><annotation encoding="application/x-tex">E</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6833em;"></span><span class="mord mathnormal" style="margin-right:0.05764em;">E</span></span></span></span>, given the number of vertices <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>V</mi></mrow><annotation encoding="application/x-tex">V</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6833em;"></span><span class="mord mathnormal" style="margin-right:0.22222em;">V</span></span></span></span> will always be less than or equal to <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msup><mi>V</mi><mn>2</mn></msup></mrow><annotation encoding="application/x-tex">V^2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.8141em;"></span><span class="mord"><span class="mord mathnormal" style="margin-right:0.22222em;">V</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height:0.8141em;"><span style="top:-3.063em;margin-right:0.05em;"><span class="pstrut" style="height:2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span></span></span></span></span></span></span></span>. <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>E</mi><mo>&lt;</mo><mo>=</mo><msup><mi>V</mi><mn>2</mn></msup></mrow><annotation encoding="application/x-tex">E &lt;= V^2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.7224em;vertical-align:-0.0391em;"></span><span class="mord mathnormal" style="margin-right:0.05764em;">E</span><span class="mspace" style="margin-right:0.2778em;"></span><span class="mrel">&lt;=</span><span class="mspace" style="margin-right:0.2778em;"></span></span><span class="base"><span class="strut" style="height:0.8141em;"></span><span class="mord"><span class="mord mathnormal" style="margin-right:0.22222em;">V</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height:0.8141em;"><span style="top:-3.063em;margin-right:0.05em;"><span class="pstrut" style="height:2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span></span></span></span></span></span></span></span>. This is because each node can at most point to itself, and every other node in the graph. If we have a node <code class="hljs language-css">A</code>, <code class="hljs language-css">B</code> and <code class="hljs language-ebnf">C</code>, <code class="hljs language-css">A</code> can point to itself, <code class="hljs language-css">B</code> and <code class="hljs language-ebnf">C</code>. The same goes for <code class="hljs language-css">B</code> and <code class="hljs language-ebnf">C</code>, so the rule checks out.</p>
<p>If the pointers connecting the edges together have a direction, we call this a <strong>directed graph.</strong> If there are edges but no direction, this is referred to as an <strong>undirected graph</strong>. For example, trees and linked lists are directed graphs because we had pointers like <code class="hljs language-ebnf">prev</code>, <code class="hljs language-python"><span class="token builtin">next</span></code> and <code class="hljs language-ebnf">left_child</code>, <code class="hljs language-ebnf">right_child</code>.</p>
<p><img src="https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/74daad67-5e27-476e-af6b-291ab5b80400/sharpen=1" alt="hello"></p>
<hr>
<h2 id="formats-of-graphs-in-interviews">Formats of Graphs in Interviews</h2>
<p>A graph can be represented in different ways. It is an abstract concept that is made concrete using different data structures. Most commonly, graphs are represented using the following:</p>
<ol>
<li>Matrix</li>
<li>Adjacency Matrix</li>
<li>Adjacency List</li>
</ol>
<h3 id="matrix">Matrix</h3>
<p>A matrix is a two-dimensional array with rows and columns, and a graph can be represented using a matrix. In the code below, each array, separated by commas, represents each row. Here we have four rows and four columns. Everything is indexed by <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>0</mn></mrow><annotation encoding="application/x-tex">0</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">0</span></span></span></span> and the idea is that we should be able to access an arbitrary row, column, or a specific element given a specified row or column. Accessing the second row can simply be done by <code class="hljs language-css">grid[1]</code> and accessing the second column may be done by <code class="hljs language-css">grid[0][1]</code>.</p>
<div class="code-toolbar"><pre class="language-cpp" tabindex="0"><code class="hljs language-cpp"><span class="token comment">// Matrix (2D Grid)</span>
<span class="token keyword">int</span> grid<span class="token punctuation">[</span><span class="token number">4</span><span class="token punctuation">]</span><span class="token punctuation">[</span><span class="token number">4</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token punctuation">{</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>How can this be used to represent a graph? As we mentioned, graphs are abstract and can be defined in many ways. Let's say that all of the 0's in our grid are vertices. To traverse a graph, we are allowed to move up, down, left and right. If we are to connect the 0s together, using our edges, we would end up getting a bunch of connected zeroes, which are connected components, and that denotes a graph. We shall discuss matrix traversal in the next chapter.</p>
<p><img src="https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/f3c04f37-7656-4836-f263-3ae19258c100/sharpen=1" alt="hello"></p>
<hr>
<h3 id="adjacency-matrix">Adjacency Matrix</h3>
<p>This is the less common input format. Here, the index of the array represents a vertex itself. Let's take an example:</p>
<div class="code-toolbar"><pre class="language-cpp" tabindex="0"><code class="hljs language-cpp"><span class="token comment">// Adjacency matrix</span>
<span class="token keyword">int</span> adjMatrix<span class="token punctuation">[</span><span class="token number">4</span><span class="token punctuation">]</span><span class="token punctuation">[</span><span class="token number">4</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token punctuation">{</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>Because the indices themselves represent a vertex, <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>0</mn></mrow><annotation encoding="application/x-tex">0</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">0</span></span></span></span> denotes that an edge does not exist between a given <code class="hljs language-smali">v1, v2</code>, and <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn></mrow><annotation encoding="application/x-tex">1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">1</span></span></span></span> denotes the opposite. <code class="hljs language-apache">adjMatrix[1][2] == 0</code> means there is no edge between vertex <code class="hljs language-undefined">1</code> and <code class="hljs language-undefined">2</code>. Also, <code class="hljs language-apache">adjMatrix[2][1] == 0</code> means there is no edge between vertex <code class="hljs language-undefined">2</code> and <code class="hljs language-undefined">1</code>. We can conclude the following from this:</p>
<div class="code-toolbar"><pre class="language-cpp" tabindex="0"><code class="hljs language-cpp"><span class="token comment">// an edge exists from v1 to v2</span>
adjMatrix<span class="token punctuation">[</span>v1<span class="token punctuation">]</span><span class="token punctuation">[</span>v2<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token number">1</span><span class="token punctuation">;</span>

<span class="token comment">// an edge exists from v2 to v1</span>
adjMatrix<span class="token punctuation">[</span>v2<span class="token punctuation">]</span><span class="token punctuation">[</span>v1<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token number">1</span><span class="token punctuation">;</span>

<span class="token comment">// No edge exists from v1 to v2</span>
adjMatrix<span class="token punctuation">[</span>v1<span class="token punctuation">]</span><span class="token punctuation">[</span>v2<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>

<span class="token comment">// No edge exists from v2 to v1</span>
adjMatrix<span class="token punctuation">[</span>v2<span class="token punctuation">]</span><span class="token punctuation">[</span>v1<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>To actualize the above adjacency matrix, we can look at the following visual.</p>
<p><img src="https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/02f2aedd-88d5-461d-9fdd-0bffc2e81400/sharpen=1" alt="hello"></p>
<p>The issue with this is that it is a giant memory hog. Because it is a square matrix, the time complexity is <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><msup><mi>V</mi><mn>2</mn></msup><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(V^2)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1.0641em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord"><span class="mord mathnormal" style="margin-right:0.22222em;">V</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height:0.8141em;"><span style="top:-3.063em;margin-right:0.05em;"><span class="pstrut" style="height:2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span></span></span></span></span><span class="mclose">)</span></span></span></span>, where <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>V</mi></mrow><annotation encoding="application/x-tex">V</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6833em;"></span><span class="mord mathnormal" style="margin-right:0.22222em;">V</span></span></span></span> is the number of vertices. This makes sense since the number of edges is also equal to the number of nodes.</p>
<hr>
<h3 id="adjacency-list">Adjacency List</h3>
<p>These are typically the most common way of representing graphs. This is also a two dimensional array. The convenience here is that we can declare it using a class called <code class="hljs language-ebnf">GraphNode</code> and it contains a list attribute called <code class="hljs language-ebnf">neighbors</code>, using which we can access all of a given vertex's neighbor.</p>
<div class="code-toolbar"><pre class="language-cpp" tabindex="0"><code class="hljs language-cpp"><span class="token keyword">class</span> <span class="token class-name">GraphNode</span> <span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
    <span class="token keyword">int</span> val_<span class="token punctuation">;</span>
    vector<span class="token operator">&lt;</span><span class="token keyword">int</span><span class="token operator">&gt;</span> neighbors_<span class="token punctuation">;</span>
    <span class="token function">GraphNode</span><span class="token punctuation">(</span><span class="token keyword">int</span> val<span class="token punctuation">)</span> <span class="token punctuation">{</span>
        val_ <span class="token operator">=</span> val<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>This ends up being more space efficient because we only care about nodes that are connected.</p>
<p><img src="https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/85b20b68-357a-4a6d-7c7a-e09256693200/sharpen=1" alt="hello"></p>
<p>In the next few chapters, we will discuss how we can perform graph traversal, using all the above mentioned formats and what kind of problems we can solve using graphs.</p>
<hr>
</div>
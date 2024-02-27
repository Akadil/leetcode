<div class="my-div"><h1 id="hash-usage">Hash Usage</h1>
<hr>
<p>Having talked about TreeSets and TreeMaps in the previous chapter, let's discuss how the map and the set interface can be implemented using hashing. In this chapter, we will be focusing on the usage of a HashSet and a HashMap, with the next chapter covering their implementation under the hood.</p>
<p>Hash maps are probably one of the most useful data structures/concepts for coding interviews, for reasons we will discuss soon. They are also extremely ubiquitous in interviews. When questions ask "unique, count, frequency", take hash maps out your arsenal. </p>
<p>Recall that the difference between a set and a map is that in sets do not map their keys to anything, whereas maps have key-value pairs.</p>
<hr>
<h2 id="motivation">Motivation</h2>
<p>Let's start off by comparing hash maps to tree maps and sorted arrays and understand what trade-offs we make using each data structure.</p>
<table class="table is-bordered">
<thead>
<tr>
<th>Operation</th>
<th>TreeMap</th>
<th>HashMap</th>
<th>Array</th>
</tr>
</thead>
<tbody><tr>
<td>Insert</td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
</tr>
<tr>
<td>Remove</td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
</tr>
<tr>
<td>Search</td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span>, if sorted</td>
</tr>
<tr>
<td>Inorder Traversal</td>
<td><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></td>
<td>-</td>
<td>-</td>
</tr>
</tbody></table>
<blockquote>
<p>The time complexity listed in the table for hash maps is the average case time complexity. However, it is widely accepted in interviews to assume constant time complexity.</p>
</blockquote>
<h3 id="tree-maps-vs-hash-maps">Tree Maps vs Hash Maps</h3>
<p>The downside of hash maps is that they are not ordered, so there is no guarantee that the map will store the values in set positions like BSTs or arrays do. If you were to iterate through all the keys, you would first need to sort them and then traverse, which will run in <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mtext>&nbsp;</mtext><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n\ log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mspace">&nbsp;</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span> time.</p>
<p>Because hashmaps don't allow duplicates and have key-value pairs, we can use them to count frequency of keys. Going back to our phonebook example, we can count the number of times a given name appears in our phonebook by mapping the name to its frequency.</p>
<p>Given the array below, we can add all the elements into a hash map as keys. Because hash maps do not allow duplicates, we can use this to our advantage. If a name already exists in our hash map as the key and we encounter it again in our array, we can just increment its value by 1. If the name does not exist, we can add it to our hash map and set the frequency to 1.</p>
<p><code class="hljs language-css">[<span class="token string">"alice"</span><span class="token punctuation">,</span> <span class="token string">"brad"</span><span class="token punctuation">,</span> <span class="token string">"collin"</span><span class="token punctuation">,</span> <span class="token string">"brad"</span><span class="token punctuation">,</span> <span class="token string">"dylan"</span><span class="token punctuation">,</span> <span class="token string">"kim"</span>]</code></p>
<table class="table is-bordered">
<thead>
<tr>
<th>Key</th>
<th>Value</th>
</tr>
</thead>
<tbody><tr>
<td>Alice</td>
<td>1</td>
</tr>
<tr>
<td>Brad</td>
<td>2</td>
</tr>
<tr>
<td>Collin</td>
<td>1</td>
</tr>
<tr>
<td>Dylan</td>
<td>1</td>
</tr>
<tr>
<td>Kim</td>
<td>1</td>
</tr>
</tbody></table>
<p>The following code demonstrates how the above operation will execute. </p>
<div class="code-toolbar"><pre class="language-cpp" tabindex="0"><code class="hljs language-cpp">vector<span class="token operator">&lt;</span>string<span class="token operator">&gt;</span> names <span class="token operator">=</span> <span class="token punctuation">{</span><span class="token string">"alice"</span><span class="token punctuation">,</span> <span class="token string">"brad"</span><span class="token punctuation">,</span> <span class="token string">"collin"</span><span class="token punctuation">,</span> <span class="token string">"brad"</span><span class="token punctuation">,</span> <span class="token string">"dylan"</span><span class="token punctuation">,</span> <span class="token string">"kim"</span><span class="token punctuation">}</span><span class="token punctuation">;</span>
unordered_map<span class="token operator">&lt;</span>string<span class="token punctuation">,</span> <span class="token keyword">int</span><span class="token operator">&gt;</span> countMap<span class="token punctuation">;</span>
<span class="token keyword">for</span> <span class="token punctuation">(</span>string<span class="token operator">&amp;</span> name<span class="token operator">:</span> names<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>countMap<span class="token punctuation">.</span><span class="token function">count</span><span class="token punctuation">(</span>name<span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        countMap<span class="token punctuation">[</span>name<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token number">1</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span> <span class="token keyword">else</span> <span class="token punctuation">{</span>
        countMap<span class="token punctuation">[</span>name<span class="token punctuation">]</span><span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
<span class="token punctuation">}</span>
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>The above algorithm, when implemented using a hash map, is more efficient than using a tree map. With a tree map, the insertion operation would cost <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span> time and if <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span> is the size of the array, it would total to <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mtext>&nbsp;</mtext><mi>l</mi><mi>o</mi><mi>g</mi><mtext>&nbsp;</mtext><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n\ log\ n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mspace">&nbsp;</span><span class="mord mathnormal" style="margin-right:0.01968em;">l</span><span class="mord mathnormal">o</span><span class="mord mathnormal" style="margin-right:0.03588em;">g</span><span class="mspace">&nbsp;</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span> time. This only costs <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span> in the case of a hash map. </p>
<hr>
<h2 id="closing-notes">Closing Notes</h2>
<p>While hash maps certainly beat tree maps and sorted arrays on paper when it comes to time complexity, we shall see that they actually take up more space compared to arrays. They can actually be a gigantic memory hog.  </p>
<hr>
</div>
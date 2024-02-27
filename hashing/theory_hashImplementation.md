<div class="my-div"><h1 id="hash-implementation">Hash Implementation</h1>
<hr>
<p>Before diving into this chapter, we would like to preface it by saying that it is unlikely that you are asked to code the implementation of a hash map from scratch in an interview. However, the knowledge we will cover in this chapter will be useful for you.</p>
<p>Hash maps are most commonly implemented using arrays under the hood. Our hash map can be of size zero but initially our array will not be of size zero.</p>
<p>Suppose that we want to fill up our array with the follow <strong>key-value</strong> pairs.</p>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">hashmap.put("Alice", "NYC")
hashmap.put("Brad", "Chicago")
hashmap.put("Collin", "Seattle")
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<p>To do so, we need to introduce something called <strong>hashing</strong> and the <strong>hash function</strong>. A hash function takes the key (a string in this case) and converts it into an integer. The same string will always always result in the same integer. Using this integer, we can determine the location at which we wish to store our <strong>key-value pair</strong>.</p>
<hr>
<h2 id="insertion-and-hashing">Insertion and Hashing</h2>
<p>Take <code class="hljs language-java"><span class="token string">"Alice"</span></code> for example. Our hash function will take each character in the string and get its ASCII code. Then it will add up the ASCII codes to determine where it should end up in the array. However, since this can be a massive number and can easily go out of bounds, we can use the modulo operator. Let's imagine that summing up all the ASCII codes for all the characters in <code class="hljs language-java"><span class="token string">"Alice"</span></code> is <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>25</mn></mrow><annotation encoding="application/x-tex">25</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">25</span></span></span></span>. To determine its location in the array, we can use the formula: <code class="hljs language-fortran">sum of ASCII codes mod size of the array</code>. In this case, the size is <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>2</mn></mrow><annotation encoding="application/x-tex">2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">2</span></span></span></span>. So, <code class="hljs language-basic">25 mod 2</code> results in <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn></mrow><annotation encoding="application/x-tex">1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">1</span></span></span></span>, which is where we store the first key value pair. The process is also sometimes known as <strong>pre-hashing</strong>.</p>
<p>Because the size of our array is only <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>2</mn></mrow><annotation encoding="application/x-tex">2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">2</span></span></span></span>, it is entirely possible that another key-value pair results in the same array position when we take the mod. This is called a <strong>collision</strong> and collisions are very common. There are ways to try and minimize collisions but they are quite inevitable. We will discuss collisions in more detail shortly.</p>
<p>To ensure each key-value pair finds a vacant spot, we will keep track of the size of the array, and the number of indices that are actually full. The way to do this is to: <code class="hljs language-apache">capacity * 2</code>, where <code class="hljs language-ebnf">capacity</code> is the size of the array, or when the hash map becomes half full, meaning half of the indices in the array are occupied. In this case, we have a size of <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>2</mn></mrow><annotation encoding="application/x-tex">2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">2</span></span></span></span> and because adding <code class="hljs language-json"><span class="token property">"Alice"</span> <span class="token operator">:</span> <span class="token string">"NYC"</span></code> will result in the map being half full, we will double its size <em>before</em> performing the next insertion. The sizing works the same as we described in the dynamic arrays chapter.</p>
<blockquote>
<p>We don't resize the array at the time of insertion of a new key-value pair, but rather as soon as the array becomes half full. This ensures that we minimize collisons before insertion.</p>
</blockquote>
<p>Once we perform the resize, we perform an operation called <strong>re-hashing</strong>. This is needed because the size of the array has changed. Rehashing tells us to re-compute the position of all the elements that already exist in the hash map. We inserted <code class="hljs language-java"><span class="token string">"Alice"</span></code> at index <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn></mrow><annotation encoding="application/x-tex">1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">1</span></span></span></span>. After doubling the size of the array, the new position of <code class="hljs language-java"><span class="token string">"Alice"</span></code>, in this case, just happens to be at index <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn></mrow><annotation encoding="application/x-tex">1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">1</span></span></span></span> again so we don't need to update it. However, if <code class="hljs language-java"><span class="token string">"Alice"</span></code>'s new position was now at index <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>2</mn></mrow><annotation encoding="application/x-tex">2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">2</span></span></span></span>, we would need to move it.</p>
<blockquote>
<p>We need to perform re-hashing if we want to maintain the <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span> time complexity for our operations. We initially started with an array of size <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>2</mn></mrow><annotation encoding="application/x-tex">2</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">2</span></span></span></span>. Let's say that we wanted to insert <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>10</mn><mo separator="true">,</mo><mn>000</mn></mrow><annotation encoding="application/x-tex">10,000</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.8389em;vertical-align:-0.1944em;"></span><span class="mord">10</span><span class="mpunct">,</span><span class="mspace" style="margin-right:0.1667em;"></span><span class="mord">000</span></span></span></span> key-value pairs into the array. When we wish to search <code class="hljs language-java"><span class="token string">"Alice"</span></code>, we would calculate the position using the new size, and <code class="hljs language-java"><span class="token string">"Alice"</span></code> might not be in that position anymore!</p>
</blockquote>
<p>Suppose that converting <code class="hljs language-java"><span class="token string">"Brad"</span></code> to integer results in <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>27</mn></mrow><annotation encoding="application/x-tex">27</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">27</span></span></span></span>. <code class="hljs language-basic">27 mod 4 = 3</code>, meaning that <code class="hljs language-json"><span class="token property">"Brad"</span> <span class="token operator">:</span> <span class="token string">"Chicago"</span></code> would end up in the <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>3</mn></mrow><annotation encoding="application/x-tex">3</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">3</span></span></span></span>rd index. Now, we will double the size to be size <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>8</mn></mrow><annotation encoding="application/x-tex">8</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">8</span></span></span></span>.</p>
<p>We have demonstrated the insertions in the visual below.</p>
<hr>
<h2 id="collisions">Collisions</h2>
<p>Suppose converting <code class="hljs language-java"><span class="token string">"Collin"</span></code> to an integer results in <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>33</mn></mrow><annotation encoding="application/x-tex">33</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">33</span></span></span></span>. <code class="hljs language-basic">33 mod 8 = 1</code>. This is a collision since Alice already resides in the first index. How do we go about resolving this? Okay, we could just overwrite but that would mean that we end up losing <code class="hljs language-java"><span class="token string">"Alice"</span></code>. We could also keep increasing the size of the array until we find a vacant space for <code class="hljs language-java"><span class="token string">"Collin"</span></code>. This, however is a gigantic memory hog.</p>
<p>There are two common ways in which we can deal with collisions:</p>
<p><strong>1. Chaining</strong></p>
<p>Chaining (recall the concept from the Linked List chapter) is achieved by chaining Linked List nodes together, so that multiple key-value pairs can be stored at the same index.</p>
<p>Because Alice and Collin belong to the same index, we can store them as a linked list object. In this case, the time complexity comes down to <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:1em;vertical-align:-0.25em;"></span><span class="mord mathnormal" style="margin-right:0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span>, for searching, inserting and deleting. This way, any future keys that belong to the same index will be stored as a node in the linked list chain.</p>
<p>The visual below demonstrates this.</p>
<p><strong>2. Open Addressing</strong><br>The idea behind open addressing is to find the next available slot so that we don't store more than one key-value pair in one index. This technique, compared to chaining is more efficient if there are a small number of collisions. The limitation here however is that the total number of entries in the table is limited by the size of the array.</p>
<p><img src="https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/32cd21d1-9655-408f-858b-5b35c2ddf800/sharpen=1" alt="hashing"></p>
<blockquote>
<p>To reduce the amount of collisions that occur, it mathematically makes sense to choose the hashmap to be of a prime size. This is because the prime number is only divisible by <span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn></mrow><annotation encoding="application/x-tex">1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height:0.6444em;"></span><span class="mord">1</span></span></span></span> and itself! This post from <a href="https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function">CS StackExchange</a> provides a mathematical proof if you are interested.</p>
</blockquote>
<hr>
<h2 id="code-implementation">Code Implementation</h2>
<p>Now that we understand the concept behind hashing, its implementation, searching, deletion, insertion and how a hash function works, let's take a look at how we would go about implementing it in code.</p>
<blockquote>
<p>We will store a list of <code class="hljs language-ebnf">Pair</code>s in our array, for which we declare a class.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">class Pair:
    constructor(key, val):
        key = key
        val = val
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>We initialize a size, capacity and the map itself in our constructor. Here, <code class="hljs language-arduino">size</code> refers to the size of the hash map and <code class="hljs language-ebnf">capacity</code> refers to size of the array under the hood.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">class HashMap:
    // Global variables
    size, capacity, map
    constructor(size, capacity, map):
        size = 0
        capacity = 2
        map = [None, None]
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>The hash function below iterates through each of the characters in a given key, sums up their ASCII code and finds the position of the key in the array.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">fn hash(key):
    index = 0
    for each character in key:
        index += get the ASCII code for each character
    // Compute the position of the character in the array
    return index % capacity
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>To retrieve the value, we first need to retrieve the position and check if the value exists in that position. If it does, we can return that value. Otherwise, we can perform open addressing and look for it in the next available index.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">fn get(key):
    index = hash(key)

    while map[index] != null:
        if map[index].key == key:
            return map[index].val
        index += 1
        index = index % capacity
    return null
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>To add to the map, we first compute the hash of the key and find the position. Once this is calculated, there are three scenarios.</p>
<ol>
<li>The index is occupied</li>
<li>The index is occupied with the same key</li>
<li>The index is vacant</li>
</ol>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">'map' is a global variable

fn put(key, val):
    // Compute the position at which the key belongs
    index = hash(key)

    while true:
        // If the positioin is vacant, add the key-value pair
        if map[index] == null:
            map[index] = new Pair(key, val)
            size += 1
            if size &gt;= capacity // 2:
                rehash()
            return
        // If the same key already exists at the index, just update the value
        else if map[index].key == key:
            map[index].val = val
            return
        // Otherwise, keep looking for the next empty index
        index += 1
        index = index % capacity
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>To remove, we find the index, remove the key, and set the index to null.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">fn remove(key):
    if get(key) does not exist:
        return
    index = hash(key)
    while True:
        if map[index].key == key:
            // Removing an element using open-addressing actually causes a bug,
           // because we may create a hole in the list, and our get() may
          // stop searching early when it reaches this hole.
            map[index] = null
            size -= 1
            return
        index += 1
        index = index % capacity
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>When we perform re-hashing, we double the capacity, copy our previous map's values into our new map and set the size to be zero.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">def rehash(self):
    capacity = 2 * capacity
    newMap = []
    for i = 0 until capacity:
        newMap.append(None)

    oldMap = map
    map = newMap
    size = 0
    for pair in oldMap:
        if pair:
            put(pair.key, pair.val)
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<blockquote>
<p>Finally, if we wish to print all of the pairs, it would look like the following.</p>
</blockquote>
<div class="code-toolbar"><pre class="language-markup" tabindex="0"><code class="language-markup">fn print():
    for every pair in our map:
        if pair is not null:
            print(pair.key, pair.val)
</code></pre><div class="toolbar"><div class="toolbar-item"><button class="copy-to-clipboard-button" type="button" data-copy-state="copy"><span>Copy</span></button></div></div></div>
<hr>
<h2 id="closing-notes">Closing Notes</h2>
<p>We could go into detail for discussing why all of these operations run in constant-time, but it is not necessary for the sake of coding interviews. If you made it this far and took nothing from this chapter apart from understanding the time complexity, you are far ahead of most people.</p>
<hr>
</div>
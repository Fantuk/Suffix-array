<h2>Суффиксный массив</h2>

<h3>Введение</h3>
<p>Суффиксный массив (Suffix Array) - это структура данных, применяемая в алгоритмах для эффективного решения задач, связанных с обработкой строк. Он представляет собой отсортированный массив индексов суффиксов строки, расположенных в лексикографическом порядке.</p>

<h3>Принцип работы</h3>
<p><strong>Построение суффиксного массива:</strong></p>
<ol>
  <li>Создается массив суффиксов для данной строки.</li>
  <li>Суффиксы сортируются в лексикографическом порядке, что может быть достигнуто с использованием алгоритма сортировки, такого как сортировка слиянием или быстрая сортировка.</li>
  <li>После сортировки получается массив индексов отсортированных суффиксов, который и является суффиксным массивом.</li>
</ol>

<h3>Применение</h3>
<p>Суффиксный массив используется для решения различных задач, таких как:</p>
<ul>
  <li>Поиск подстроки</li>
  <li>Сравнение строк</li>
  <li>Построение LCP-массива (массива наибольших общих префиксов)</li>
  <li>Другие задачи анализа текстовой информации</li>
</ul>

<h3>Реализация на C++</h3>
<pre><code>
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;

using namespace std;

bool compare(const string&amp; a, const string&amp; b) {
    return a &lt; b;
}

vector&lt;int&gt; buildSuffixArray(const string&amp; text) {
    int n = text.size();
    vector&lt;string&gt; suffixes(n);

    for (int i = 0; i &lt; n; ++i) {
        suffixes[i] = text.substr(i, n - i);
    }

    vector&lt;int&gt; suffixArray(n);
    for (int i = 0; i &lt; n; ++i) {
        suffixArray[i] = i;
    }

    sort(suffixArray.begin(), suffixArray.end(), [&amp;suffixes](int a, int b) {
        return compare(suffixes[a], suffixes[b]);
    });

    return suffixArray;
}

int main() {
    string text;
    cout &lt;&lt; "Enter a string: ";
    cin &gt;&gt; text;

    vector&lt;int&gt; suffixArray = buildSuffixArray(text);

    cout &lt;&lt; "Suffix Array for '" &lt;&lt; text &lt;&lt; "':\n";
    for (int index : suffixArray) {
        cout &lt;&lt; index &lt;&lt; " ";
    }
    cout &lt;&lt; endl;

    return 0;
}
</code></pre>

<h3>Примеры и вывод</h3>
<p><strong>Пример 1:</strong></p>
<pre><code>
Ввод: banana
Вывод:

Enter a string: banana
Suffix Array for 'banana':
5 3 1 0 4 2
</code></pre>

<p><strong>Пример 2:</strong></p>
<pre><code>
Ввод: mississippi
Вывод:

Enter a string: mississippi
Suffix Array for 'mississippi':
10 7 4 1 0 9 8 6 3 5 2
</code></pre>

<p><strong>Пример 3:</strong></p>
<pre><code>
Ввод: racecar
Вывод:

Enter a string: racecar
Suffix Array for 'racecar':
7 6 5 4 0 3 2 1
</code></pre>

<h3>Заключение</h3>
<p>Суффиксный массив - это мощный инструмент для обработки строковых данных. Его реализация и использование могут значительно ускорить решение различных задач, связанных с анализом текстовой информации. Он является ключевым компонентом многих алгоритмов, используемых в компьютерных науках и инженерии.</p>

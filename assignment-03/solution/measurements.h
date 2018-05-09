<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
          "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    
    <title>CppPC - assignment-03/a-03/solution/measurements.h</title>
        <link href="/css/custom.css" rel="stylesheet" media="screen, projection" type="text/css" />
    <link href="/css/print.css" rel="stylesheet" media="print" type= "text/css" />
    
    <!--[if IE]><link href="/css/ie.css" rel="stylesheet" media="screen, projection" type="text/css" /><![endif]-->
  </head>
  <body>
    <div id="doc3" class="yui-t1">
        <div id="yui-main">
          <div id="maincol" class="yui-b">
            <div id="userbox">
  <noscript>
    <a href="/_login">Login</a>
    <a href="/_logout">Logout</a>
  </noscript>
  &nbsp;
  <a id="loginlink" class="login" href="/_login">Login / Get an account</a>
  <a id="logoutlink" class="login" href="/_logout">Logout <span id="logged_in_user"></span></a>
</div>
            <ul class="tabs"
><li class="selected"
  ><a href="/assignment-03/a-03/solution/measurements.h"
    >view</a
    ></li
  ><li
  ><a href="/_history/assignment-03/a-03/solution/measurements.h"
    >history</a
    ></li
  ></ul
> 
            <div id="content">
  
  <h1 class="pageTitle"><a href="/assignment-03/a-03/solution/measurements.h">assignment-03/a-03/solution/measurements.h</a></h1>
  
  <div class="sourceCode"><table class="sourceCode"><tr class="sourceCode"><td class="lineNumbers"><pre><a id="1" href="#1">1</a>
<a id="2" href="#2">2</a>
<a id="3" href="#3">3</a>
<a id="4" href="#4">4</a>
<a id="5" href="#5">5</a>
<a id="6" href="#6">6</a>
<a id="7" href="#7">7</a>
<a id="8" href="#8">8</a>
<a id="9" href="#9">9</a>
<a id="10" href="#10">10</a>
<a id="11" href="#11">11</a>
<a id="12" href="#12">12</a>
<a id="13" href="#13">13</a>
<a id="14" href="#14">14</a>
<a id="15" href="#15">15</a>
<a id="16" href="#16">16</a>
<a id="17" href="#17">17</a>
<a id="18" href="#18">18</a>
<a id="19" href="#19">19</a>
<a id="20" href="#20">20</a>
<a id="21" href="#21">21</a>
<a id="22" href="#22">22</a>
<a id="23" href="#23">23</a>
<a id="24" href="#24">24</a>
<a id="25" href="#25">25</a>
<a id="26" href="#26">26</a>
<a id="27" href="#27">27</a>
<a id="28" href="#28">28</a>
<a id="29" href="#29">29</a>
<a id="30" href="#30">30</a>
<a id="31" href="#31">31</a>
<a id="32" href="#32">32</a>
<a id="33" href="#33">33</a>
</pre></td><td class="sourceCode"><pre><code class="sourceCode"><span class="ot">#ifndef CPPPC__A03__MEASUREMENTS_H__INCLUDED</span>
<span class="ot">#define CPPPC__A03__MEASUREMENTS_H__INCLUDED</span>

<span class="ot">#include &lt;vector&gt;</span>
<span class="ot">#include &lt;cmath&gt;</span>

namespace cpppc {

template &lt;typename T&gt;
class Measurements
{

  <span class="kw">typedef</span> Measurements&lt;T&gt;                                   self_t;
  <span class="kw">typedef</span> T                                                value_t;

  <span class="kw">typedef</span>       T &amp;                                      reference;
  <span class="kw">typedef</span> <span class="dt">const</span> T &amp;                                const_reference;
  <span class="kw">typedef</span> typename std::vector&lt;T&gt;::iterator               iterator;
  <span class="kw">typedef</span> typename std::vector&lt;T&gt;::const_iterator   const_iterator;

public:

  <span class="co">// YOUR IMPLEMENTATION HERE</span>

private:

  std::vector&lt;T&gt; _values;

};

} <span class="co">// namespace cpppc</span>

<span class="ot">#endif </span><span class="co">// CPPPC__A03__MEASUREMENTS_H__INCLUDED</span></code></pre></td></tr></table></div>
</div>
            <div id="footer">powered by <a href="http://github.com/jgm/gitit/tree/master/">gitit</a></div>
          </div>
        </div>
        <div id="sidebar" class="yui-b first">
          <div id="logo">
  <a href="/" alt="site logo" title="Go to top page"><img src="/img/logo.png" /></a>
</div>
                      <div class="sitenav">
  <fieldset>
    <legend>Site</legend>
    <ul>
      <li><a href="/">Front page</a></li>
      <li><a href="/_index">All pages</a></li>
      <li><a href="/_categories">Categories</a></li>
      <li><a href="/_random">Random page</a></li>
      <li><a href="/_activity">Recent activity</a></li>
              <li><a href="/_upload">Upload a file</a></li>
      
      
      <li><a href="/Help">Help</a></li>
    </ul>
    <form action="/_search" method="get" id="searchform">
     <input type="text" name="patterns" id="patterns"/>
     <input type="submit" name="search" id="search" value="Search"/>
    </form>
    <form action="/_go" method="post" id="goform">
      <input type="text" name="gotopage" id="gotopage"/>
      <input type="submit" name="go" id="go" value="Go"/>
    </form>
  </fieldset>
</div>
          
                      <div class="pageTools">
  <fieldset>
    <legend>This page</legend>
    <ul>
      <li><a href="/_showraw/assignment-03/a-03/solution/measurements.h">Raw page source</a></li>
      <li><a href="/assignment-03/a-03/solution/measurements.h?printable">Printable version</a></li>
      <li><a href="/_delete/assignment-03/a-03/solution/measurements.h">Delete this page</a></li>
      
    </ul>
    
  </fieldset>
</div>
          
          
        </div>
    </div>
    <script src="/js/jquery-1.2.6.min.js" type="text/javascript"
></script
><script src="/js/jquery-ui-combined-1.6rc2.min.js" type="text/javascript"
></script
><script src="/js/footnotes.js" type="text/javascript"
></script
>
    
    <script type="text/javascript">
/* <![CDATA[ */
  $.get("/_user", {}, function(username, status) {
     $("#logged_in_user").text(username);
     if (username == "") {  // nobody logged in
        $("#logoutlink").hide();
        $("#loginlink").show();
     } else {
        $("#logoutlink").show();
        $("#loginlink").hide();
     };
   });
/* ]]> */
</script>
  </body>
</html>
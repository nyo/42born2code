var my_element = document.getElementById('lga');
> undefined
my_element.getAttribute('id');
> "lga"

var new_element = document.createElement('span');
> undefined
new_element.setAttribute('style', 'background: red;');
> undefined
var_text = document.createTextNode('hello world');
> "hello world"
new_element.appendChild(var_text);
> "hello world"
my_element.appendChild(new_element);
> <span style="background: red;">hello world</span>
my_element.removeChild(new_element);
> <span style="background: red;">hello world</span>

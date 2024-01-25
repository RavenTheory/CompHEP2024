echo
echo '# Type these lines below in an interactive python prompt'
echo
echo
echo import sys
echo
echo 'def my_display(x):'
echo '   print("out: ", x)'
echo
echo s = \"cheese\"
echo s
echo 
echo sys.displayhook = my_display
echo s

# After defining the custom displayhook() function, here my_display, we override the default display hook by assigning our custom function to the sys.displayhook variable. This way, whenever the interpreter needs to display a result, it will use our custom display hook function instead.

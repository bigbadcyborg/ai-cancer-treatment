import matplotlib.pyplot as plt
from matplotlib_venn import venn2

# Create a Venn diagram with two intersecting sets
venn = venn2(subsets=(1, 1, 1), set_labels=('Rule Clauses', 'User Clauses'))

# Customize subset labels
if venn.get_label_by_id('10'):
    venn.get_label_by_id('10').set_text('')  # Only in A
if venn.get_label_by_id('01'):
    venn.get_label_by_id('01').set_text('')  # Only in B
if venn.get_label_by_id('11'):
    venn.get_label_by_id('11').set_text("userValidClauseVect")  # Intersection of A and B

# Show the diagram
plt.show()

set terminal png noenhanced size 640,480
set output 'hnc_gnuplot_plot_boxes_fill_pattern.png'

set title ' Fill pattern with hnc::gnuplot::plot_boxes::fill_pattern::pattern '

#set xlabel ' xlabel '
#set ylabel ' ylabel '

set yrange [0:9]
set xrange [-1:2]

plot 'hnc_gnuplot_plot_boxes_fill_pattern.data' using 0:2:(0.8):xtic(1) with boxes fill pattern 0 title 'empty', \
                                             '' using 0:3:(0.8)         with boxes fill pattern 1 title 'X', \
                                             '' using 0:4:(0.8)         with boxes fill pattern 2 title 'x', \
                                             '' using 0:5:(0.8)         with boxes fill pattern 3 title 'solid', \
                                             '' using 0:6:(0.8)         with boxes fill pattern 4 title 'diagonal', \
                                             '' using 0:7:(0.8)         with boxes fill pattern 5 title 'anti_diagonal', \
                                             '' using 0:8:(0.8)         with boxes fill pattern 6 title 'diagonal_v2', \
                                             '' using 0:9:(0.8)         with boxes fill pattern 7 title 'anti_diagonal_v2'

#!/usr/bin/env python3

import os
import os.path
import sys
import html
import glob


index_file = 'gcov.index'
htmlcov_dir = 'htmlcov'


CSS = '''<style>
    body {
        background-color: #000000;
        color: #00bb00;
        font-family: monospace;
        font-size: 14px;
        padding: 1% 1%;
        margin: 0;
    }
    </style>'''

TMPL_HEAD = '''<!doctype html>
<html>
<head>
    {css}
    <title>jcaslib tests coverage - {title}</title>
</head>
<body>
<pre>'''

TMPL_TAIL = '''</pre>
</body>
</html>'''


def html_head (out_f, title):
    with open (out_f, 'w') as fh:
        print (TMPL_HEAD.format (title = title, css = CSS), file = fh)
        fh.flush ()
        fh.close ()


def html_tail (out_f):
    with open (out_f, 'a') as fh:
        print (TMPL_TAIL, file = fh)
        fh.flush ()
        fh.close ()


def cat_file (src, dst):
    with open (src, 'r') as srcfh:
        with open (dst, 'a') as dstfh:
            for src_l in srcfh.readlines ():
                dstfh.write (html.escape (src_l))
            dstfh.flush ()
            dstfh.close ()
        srcfh.close ()


def parse_index ():
    pass


def write_gcov_index ():
    idxn = os.path.basename (index_file)
    dst = os.path.join (htmlcov_dir, idxn + '.html')
    html_head (dst, idxn);
    cat_file (index_file, dst)
    html_tail (dst);


def write_gcov_html (src):
        dst = os.path.basename (src)
        out_f = os.path.join (htmlcov_dir, dst + '.html')
        html_head (out_f, dst.replace ('.html', '', 1))
        cat_file (src, out_f)
        html_tail (out_f)


def scan_files ():
    for src in glob.glob ('*.gcov'):
        write_gcov_html (src)


def pre_checks ():
    if not os.path.isfile (index_file):
        print (index_file, "file not found")
        sys.exit (1)
    if not os.path.isdir (htmlcov_dir):
        print (htmlcov_dir, "dir not found")
        sys.exit (1)


def main ():
    pre_checks ()
    write_gcov_index ()
    scan_files ()


if __name__ == '__main__':
    sys.exit (main())

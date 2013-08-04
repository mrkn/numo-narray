static void
<%=c_iterator%>(na_loop_t *const lp)
{
    size_t  i;
    char   *p1;
    ssize_t s1;
    size_t *idx1;
    void *x;
    VALUE y;
    volatile VALUE a;
    VALUE fmt = lp->option;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1, idx1);
    a = rb_ary_new2(i);
    rb_ary_push(lp->args[1].value, a);
    for (; i--;) {
        LOAD_PTR_STEP(p1, s1, idx1, void, x);
        y = format_<%=tp%>(fmt, x);
        rb_ary_push(a,y);
    }
}

/*
  Format elements into strings.
  @overload <%=op_map%> format
  @param [String] format
  @return [Array] array of formated strings.
*/
static VALUE
<%=c_instance_method%>(int argc, VALUE *argv, VALUE self)
{
    volatile VALUE fmt=Qnil;
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{sym_loop_opt},{sym_option}};
    ndfunc_arg_out_t aout[1] = {{rb_cArray,0}}; // dummy?
    ndfunc_t ndf = { <%=c_iterator%>, FULL_LOOP, 3, 1, ain, aout };

    rb_scan_args(argc, argv, "01", &fmt);
    return na_ndloop_cast_narray_to_rarray(&ndf, self, fmt);
}
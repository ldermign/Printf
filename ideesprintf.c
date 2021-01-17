t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_is_in_type_list(save[i])
		&& !ft_is_in_flags_list(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_is_in_type_list(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}




/////


void	ft_init_struct(t_printf *tab)
{
	tab->buf_count = 0;
	tab->ret = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->precision_parsing = 0;
	tab->converter = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->len = 0;
	tab->sp_len = 0;
	tab->is_int = 0;
	tab->h_count = 0;
	tab->l_count = 0;
	tab->n = 0;
	tab->u = 0;
	tab->i = 0;
}

int		ft_printf(const char *str, ...)
{
	t_printf	tab;
	va_list		ap;

	ft_init_struct(&tab);
	va_start(ap, str);
	while (str[tab.i])
	{
		if (str[tab.i] == '%')
		{
			if (str[tab.i + 1] == '\0')
				break ;
			if (ft_is_from_pf(str[tab.i + 1]))
				ft_parse((char*)str, ap, &tab);
		}
		else
			ft_print_normal(&tab, (char*)str);
		tab.i++;
	}
	va_end(ap);
	ft_dump_buffer(&tab);
	return (tab.ret);
}

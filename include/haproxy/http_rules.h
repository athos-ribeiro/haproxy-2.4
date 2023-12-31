/*
 * include/haproxy/http_rules.h
 * This file contains "http" rules definitions
 *
 * Copyright (C) 2000-2018 Willy Tarreau - w@1wt.eu
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, version 2.1
 * exclusively.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _HAPROXY_HTTP_RULES_H
#define _HAPROXY_HTTP_RULES_H

#include <haproxy/action-t.h>
#include <haproxy/api.h>
#include <haproxy/list.h>
#include <haproxy/proxy-t.h>

extern struct action_kw_list http_req_keywords;
extern struct action_kw_list http_res_keywords;
extern struct action_kw_list http_after_res_keywords;

struct act_rule *parse_http_req_cond(const char **args, const char *file, int linenum, struct proxy *proxy);
struct act_rule *parse_http_res_cond(const char **args, const char *file, int linenum, struct proxy *proxy);
struct act_rule *parse_http_after_res_cond(const char **args, const char *file, int linenum, struct proxy *proxy);
void  http_free_redirect_rule(struct redirect_rule *rdr);
struct redirect_rule *http_parse_redirect_rule(const char *file, int linenum, struct proxy *curproxy,
                                               const char **args, char **errmsg, int use_fmt, int dir);

static inline void http_req_keywords_register(struct action_kw_list *kw_list)
{
	LIST_APPEND(&http_req_keywords.list, &kw_list->list);
}

static inline void http_res_keywords_register(struct action_kw_list *kw_list)
{
	LIST_APPEND(&http_res_keywords.list, &kw_list->list);
}

static inline void http_after_res_keywords_register(struct action_kw_list *kw_list)
{
	LIST_APPEND(&http_after_res_keywords.list, &kw_list->list);
}

struct action_kw *action_http_req_custom(const char *kw);
struct action_kw *action_http_res_custom(const char *kw);
struct action_kw *action_http_after_res_custom(const char *kw);

#endif /* _HAPROXY_HTTP_RULES_H */

/*
 * Local variables:
 *  c-indent-level: 8
 *  c-basic-offset: 8
 * End:
 */

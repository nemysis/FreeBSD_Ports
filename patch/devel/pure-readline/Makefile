# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/devel/pure-readline/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-readline
PORTVERSION=	0.2
CATEGORIES=	devel
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Readline interface for the Pure language

LICENSE=	BSD GPLv3
LICENSE_COMB=	dual

USES=		pure

PLIST_FILES=	lib/pure/readline.pure \
		lib/pure/readline.so

PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD: head/net/enet/Makefile 313615 2013-03-08 05:35:50Z beech $

PORTNAME=	enet
PORTVERSION=	1.3.8
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple and robust communication library based on UDP

LICENSE=	MIT

USES=		pathfix
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	aclocal automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>

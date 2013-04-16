# New ports collection makefile for:   dd_rescue
# Date created:        14 March 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD: head/sysutils/dd_rescue/Makefile 311038 2013-01-26 18:03:42Z nobutaka $
#

PORTNAME=	dd_rescue
PORTVERSION=	1.32
CATEGORIES=	sysutils
MASTER_SITES=	http://www.garloff.de/kurt/linux/ddrescue/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A dd tool suitable for rescuing data from a medium with errors

LICENSE=	GPLv2

USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README.dd_rescue

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

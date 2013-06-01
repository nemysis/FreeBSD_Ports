# Created by: Marc Bruenink
# $FreeBSD: head/net-im/coccinella/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	coccinella
PORTVERSION=	0.96.20
PORTREVISION=	1
CATEGORIES=	net-im tk
MASTER_SITES=	SF
DISTNAME=	Coccinella-${PORTVERSION}Src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber client with whiteboard communication

LICENSE=	GPLv3

RUN_DEPENDS=	snack>=0:${PORTSDIR}/audio/snack \
		tcltls>=0:${PORTSDIR}/devel/tcltls \
		tkpng>=0:${PORTSDIR}/graphics/tkpng \
		tktray>=0:${PORTSDIR}/x11-toolkits/tktray \
		tktreectrl>=0:${PORTSDIR}/x11-toolkits/tktreectrl

NO_BUILD=	yes
USE_TK_WRAPPER=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS.txt CHANGES.txt README.txt

DOCSRCDIR2=	${WRKSRC}/READMEs
DOCSDIR2=	${DOCSDIR}/READMEs
DOC_FILES2=	*

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Coccinella.tcl ${DATADIR}
	@${LN} -sf ${DATADIR}/Coccinella.tcl ${PREFIX}/bin/coccinella
.for dir in TclXML certificates components contrib docs httpd iconsets items \
	jabber jabberlib lib plugins resources themes whiteboard xmpp
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor

.if ${PORT_OPTIONS:MNLS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "msgs po" ${DATADIR})
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>

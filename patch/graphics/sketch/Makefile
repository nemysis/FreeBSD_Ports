# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD: head/graphics/sketch/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	sketch
PORTVERSION=	0.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.frontiernet.net/~eugene.ressler/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	3D Scene Description Translator

LICENSE=	GPLv3

USE_GMAKE=	yes
MAKEFILE=	makefile
USE_PERL5_BUILD=yes
USE_DOS2UNIX=	*.htm *.html *.info *.pl *.sk *.tex *.texi *.txt

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	readme updates.htm

DOCSRCDIR2=	${WRKSRC}/Doc/sketch
DOCSDIR2=	${DOCSDIR}/Doc/sketch
DOC_FILES2=	*

DOCSRCDIR3=	${WRKSRC}/Doc
DOCSDIR3=	${DOCSDIR}/Doc
DOC_FILES3=	*.eps *.pdf *.png *.sk *.txt *.tex *.texi
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*.sk
.endif

PLIST_FILES=	bin/sketch

do-build:
	cd ${WRKSRC} && ${GMAKE} CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
	@${MKDIR} ${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${DOCSDIR3}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/Data && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

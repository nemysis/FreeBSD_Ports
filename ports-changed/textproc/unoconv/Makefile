# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/textproc/unoconv/Makefile 304580 2012-09-20 14:22:09Z pawel $

PORTNAME=	unoconv
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://dag.wieers.com/home-made/unoconv/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convert any document from and to any LibreOffice supported format

LICENSE=	GPLv2

RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README.asciidoc WISHLIST

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.txt

MAN1=		${PORTNAME}.1

SUB_FILES=	${PORTNAME} pkg-message

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/tests
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${DATADIR}

.for f in *.gif *.odt *.csv
	@(cd ${WRKSRC}/tests && ${INSTALL_DATA} ${f} ${DATADIR}/tests)
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>

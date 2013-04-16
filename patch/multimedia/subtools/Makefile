# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD: head/multimedia/subtools/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	subtools
PORTVERSION=	20081026
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tools for movie subtitles in SubRipper format

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_DOS2UNIX=	*.c *.py ../*.TXT

EXECS=		srtshift srtrate

PLIST_FILES=	bin/srtshift bin/srtrate bin/udvd2srt.py bin/udvdshift.py

PORTDOCS=	CHANGELOG.TXT README.TXT

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^M||g;s|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak)

do-build:
.for EXEC in ${EXECS}
	cd ${WRKSRC} && ${CC} ${CFLAGS} -D${EXEC:U} -o ${EXEC} ${PORTNAME}.c
.endfor

do-install:
.for s in ${EXECS}
	@(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${s} ${PREFIX}/bin)
.endfor
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} *.py ${PREFIX}/bin)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

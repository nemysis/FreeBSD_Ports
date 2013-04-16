# Created by: ijliao
# $FreeBSD: head/graphics/exiftags/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	exiftags
PORTVERSION=	1.01
CATEGORIES=	graphics
MASTER_SITES=	http://johnst.org/sw/exiftags/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Displaying and modifying Exif tags in digital camera JPEG files

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

MAN1=		exifcom.1 exiftags.1 exiftime.1
PORTDOCS=	CHANGES README
PLIST_FILES=	bin/exifcom bin/exiftags bin/exiftime

.include <bsd.port.options.mk>

do-install:
.for i in exifcom exiftags exiftime
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${i}.1 ${MAN1PREFIX}/man/man1
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

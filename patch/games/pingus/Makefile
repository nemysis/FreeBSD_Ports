# New ports collection makefile for:	pingus
# Date created:		2007-10-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD: head/games/pingus/Makefile 300896 2012-07-14 13:54:48Z beat $
#

PORTNAME=	pingus
PORTVERSION=	0.7.6
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
#MASTER_SITES=	http://pingus.seul.org/files/
# http://pingus.googlecode.com/files/pingus-0.7.6.tar.bz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Lemmings-like game

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		boost_regex.4:${PORTSDIR}/devel/boost-libs \
		physfs.1:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_ICONV=	yes
USE_SDL=	sdl image mixer
USE_SCONS=	yes
#SCONS_ARGS=	with_linuxusbmouse=0 \
#		with_linuxevdev=0
USE_GMAKE=	yes

#CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
#LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

#DESKTOP_ENTRIES=	"Pingus" "${COMMENT}" "" \
#			"pingus" "" false

#PLIST=		${WRKDIR}/pkg-plist

#post-patch:
#	@${REINPLACE_CMD} -e 's|add_path("data")|add_path("${DATADIR}")|g' \
#		${WRKSRC}/src/pingus_main.cpp

#pre-install:
#	@${RM} -f ${PLIST}
#	@${ECHO_CMD} "bin/${PORTNAME}" >> ${PLIST}
#	@cd ${WRKSRC}/data && \
#		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
#			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
#	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

#do-install:
#	@${MKDIR} ${DATADIR}
#	@cd ${WRKSRC}/data && \
#		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
#			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
#5	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

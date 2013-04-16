# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD: head/games/fretsonfire-data/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	data
PORTVERSION=	1.3.110
CATEGORIES=	games python
MASTER_SITES=	SF/fretsonfire/fretsonfire/${PORTVERSION}
PKGNAMEPREFIX=	fretsonfire-
DISTNAME=	${PKGNAMEPREFIX:S/f/F/g:S/o/O/}${PORTVERSION}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Frets on Fire data files

RUN_DEPENDS=	FretsOnFire:${PORTSDIR}/games/fretsonfire

NO_BUILD=	yes
DATADIR=	share/${PKGNAMEPREFIX:S/-//}
RESTRICTED=	Only Unreal Voodoo site is allowed to distribute the music
WRKSRC=		${WRKDIR}/Frets\ on\ Fire-${PORTVERSION}

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude 'win32' "Frets on Fire-${PORTVERSION}/${PORTNAME}"

do-install:
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${DATADIR}/{}" \;

.include <bsd.port.mk>
